import socket, struct

#TcpSocket class is a socket.socket inherit, that handle TCP communication message way
#All TcpSocket message are preffixed with the 4 bytes, big endian, unsigned size of that TcpSocket message
#That way if a server and a client both use the TcpSocket's mthods for message communication
#They can both ensure that the message will be send and receive entierly
#Here is the protocol picture:

# Have a variable length message: 'Msg...'
# Encode its size with struct.pack '>L' in front of it: "[4-bytes-bigEndian-unsigned-size]['Msg...']"
# Send all the packet

# Read 4 byte from the socket, unpack it with struct.unpack '>L'
# Then loop on the read socket until all that length has been read and return the message

#TcpSocket module include two other classes, TcpSocketClient and TcpSocketServer

#TcpSocketClient is a TcpSocket who try to connect when instanciate

#TcpSocketServer is a TcpSocket who bind and listen when instanciate
#TcpSocketServer also provide a wrapper for accept method in order to return a TcpSocket insteas of socket.socket

#All socket.error catched raise TcpSocketError
#Additionnaly a TcpSocketError is raise for a empty message on the socket

class TcpSocketError(Exception):
    pass

class TcpSocket(socket.socket):
    def __init__(self, fileno=None):
        self._header_size = struct.calcsize('>L')
        socket.socket.__init__(self, socket.AF_INET, socket.SOCK_STREAM, 0, fileno)

    def msg_recv(self):
        header = int(self._header_recv())
#        print 'RECV : header', header
        raw_chunk = ''
        while len(raw_chunk) < header:
            raw_chunk += self._raw_recv(header - len(raw_chunk))
#        print 'RECV :', raw_chunk, len(raw_chunk)
        return struct.unpack('%ds' % header, raw_chunk)[0]

    def msg_send(self, msg):
        self._raw_sendall(struct.pack('>L%ds' % len(msg), len(msg), msg))
#        print 'SEND :', msg, len(msg)

    def _header_recv(self):
        return struct.unpack('>L', self._raw_recv(self._header_size))[0]

    def _raw_recv(self, size):
        try:
            raw = self.recv(size)
        except socket.error as error:
            raise TcpSocketError(error)
        if not raw or len(raw) == 0:
            raise TcpSocketError('TcpSocket : Empty socket')
        return raw

    def _raw_sendall(self, raw):
        try:
            self.sendall(raw)
        except socket.error as error:
            raise TcpSocketError(error)


class TcpSocketClient(TcpSocket):
    def __init__(self, addr='localhost', port=9999):
        TcpSocket.__init__(self)
        try:
            self.connect((addr, port))
        except socket.error as error:
            raise TcpSocketError(error)


class TcpSocketServer(TcpSocket):
    def __init__(self, addr='', port=9999):
        TcpSocket.__init__(self)
        self.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        try:
            self.bind((addr, port))
        except socket.error as error:
            raise TcpSocketError(error)
        self.listen(5)

    def accept(self):
        sock, addr = socket.socket.accept(self)
        return TcpSocket(sock), addr
