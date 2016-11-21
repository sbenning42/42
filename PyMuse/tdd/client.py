from MySocket import MySocket
from threading import Thread, RLock
from time import sleep
from socket import error
from Osc import *

class MuseData(object):

    def update(self, frame):
        osc = OscMsg(frame)
        self.__dict__.update(osc.path.split('/')[-1] : osc.args)

class MuseAPI(object):
    def __init__(self, host):
        self.sock = MySocket()
        self.sock.client(host)
        self.lock = RLock()
        self.muse = MuseData()
        self._muse = MuseData()
        produce = Thread(target=self.handler)
        produce.daemon = True
        produce.start()

    def subscribe(self, k):
        self.sock.send('SUB ' + str(k))

    def unsubscribe(self, k):
        self.sock.send('UNS ' + str(k))
    
    def stop(self):
        self.sock.send('END')
        self.sock.sock.close()

    def update(self):
        with self.lock:
            self.muse.__dict__.update(enumerate(self._muse.__dict__))

    def handler(self):
        while 42:
            try:
                data = self.sock.recv()
            except error:
                break
            with self.lock:
                self._muse.update(data)
        print('Close')


api = MuseAPI(('localhost', 5001))
api.subscribe(BLINK)
now = time()
while time() < now + 42:
    print(api.muse.blink)
    api.update()
api.stop()
