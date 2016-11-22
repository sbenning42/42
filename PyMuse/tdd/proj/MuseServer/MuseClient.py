from TcpSocket import TcpSocket, error
from threading import Thread
from time import time, sleep
from Config import *
from Osc import OscMsg

class MuseMsg(OscMsg):
    def __init__(self, frame):
        OscMsg.__init__(self, frame)
        self.key = get_key_from_path(self.path)


class MuseData(object):

    def update(self, frame):
        msg = MuseMsg(frame)
        instance_name = MuseTable[msg.key]['path'].split('/')[-1]
        self.__dict__.update({instance_name : msg.args})


class Muse(object):
    def __init__(self, host):
        self.data = MuseData()
        self._data = MuseData()
        self._tcpsock = TcpSocket()
        self._tcpsock.client(host)
        self._produce()

    def subscribe(self, key):
        if not key in Keys:
            return
        msg = str(key)
        self._tcpsock.send_ascii(msg)
        instance_name = MuseTable[key]['path'].split('/')[-1]
        while not instance_name in self.data.__dict__:
            self.update()
            sleep(0.02)

    def unsubscribe(self, key):
        self.subscribe(key)

    def update(self):
        for k, v in self._data.__dict__.items():
            self.data.__dict__.update({k : v})

    def stop(self):
        self.subscribe(99)
        self._tcpsock.close()

    def _produce(self):
        producer = Thread(target=self._producer)
        producer.daemon = True
        producer.start()

    def _producer(self):
        while 42:
            try:
                frame = self._tcpsock.recv()
            except error as err:
                print(err)
                break
            self._data.update(frame)
        print('Producer Stop')

def main():
    muse = Muse((IP, CLI_PORT))
    muse.subscribe(BLINK)
    muse.subscribe(IS_GOOD)
    now = time()
    while time() < now + 42:
        print(muse.data.is_good, muse.data.blink)
        sleep(0.02)
        muse.update()
    muse.stop()

if __name__ == '__main__':
    main()
