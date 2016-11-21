from threading import Thread, RLock
from time import time, sleep
from MySocket import MySocket
from MuseKeys import *
from Osc import *

class Client(object):
    def __init__(self, sock):
        self.sock = sock
        self.sub = [False for k in Keys]

    def subs(self, req):
        if 'A' in req:
            self.sub[0] = True
        elif 'B' in req:
            self.sub[1] = True

    def uns(self, req):
        if 'A' in req:
            self.sub[0] = False
        elif 'B' in req:
            self.sub[1] = False

    def kill(self):
        self.sub = [False, False]


class Clients(object):
    def __init__(self):
        self.clients = []

    def new(self, sock):
        client = Client(sock)
        self.clients.append(client)
        return client

    def dispatch(self, frame):
        if 'A' in frame:
            for c in self.clients:
                if c.sub[0]:
                    c.sock.send(frame)
        elif 'B' in frame:
            for c in self.clients:
                if c.sub[1]:
                    c.sock.send(frame)



def handle_req(req, client):
    if 'SUB' in req:
        client.subs(req)
    elif 'UNS' in req:
        client.uns(req)
    else:
        client.kill()

def client_handler(sock, clients):
    client = clients.new(sock)
    client = Client(sock)
    while 42:
        req = sock.recv()
        handle_req(req, client)
        if 'END' in req:
            break
    print('Client handler stop')
    sock.sock.close()

def comm_handler(sock, clients):
    sock.server(('', 5001))
    while 42:
        client_sock, addr = sock.accept()
        client = Thread(target=client_handler, args=(client_sock, clients))
        client.daemon = True
        client.start()

def io_handler(sock, clients):
    sock.server(('', 5000))
    io_sock, addr = sock.accept()
    while 42:
        frame = io_sock.recv()
        clients.dispatch(frame)

def main():
    io_sock = MySocket()
    comm_sock = MySocket()
    clients = Clients()
    io = Thread(target=io_handler, args=(io_sock, clients))
    io.daemon = True
    comm = Thread(target=comm_handler, args=(comm_sock, clients))
    comm.daemon = True
    io.start()
    comm.start()
    input('Press Enter to Quit\n')

if __name__ == '__main__':
    main()
