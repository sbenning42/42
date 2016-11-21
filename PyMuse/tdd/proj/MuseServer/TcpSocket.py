from socket import *

class TcpSocket(object):

    def __init__(self):
        self.sock = socket(AF_INET, SOCK_STREAM)

    def client(self, host):
        self.sock.connect(host)
