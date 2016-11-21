from socket import socket, error, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
from struct import pack, unpack, calcsize

def make_frame(msg):
    content = msg.encode('utf-8')
    size = pack('>i', len(content))
    return size + content

class MySocket(object):
    def __init__(self, sock=None):
        if not sock:
            self.sock = socket(AF_INET, SOCK_STREAM)
        else:
            self.sock = sock

    def __del__(self):
        self.sock.close()

    def client(self, host):
        self.sock.connect(host)

    def server(self, host):
        self.sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        self.sock.bind(host)
        self.sock.listen(5)

    def accept(self):
        s, addr = self.sock.accept()
        return MySocket(s), addr

    def send(self, msg):
        frame = make_frame(msg)
        self.sock.sendall(frame)

    def recv(self):
        chunk = self.recv_loop(calcsize('>i'))
        size = unpack('>i', chunk)[0]
        frame = self.recv_loop(size)
        return frame.decode('utf-8')

    def recv_loop(self, size):
        chunk = b''
        while (len(chunk) < size):
            chunk_part = self.sock.recv(size - len(chunk))
            if not chunk_part:
                raise error('Empty Socket')
            chunk += chunk_part
        return chunk
