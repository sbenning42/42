import socket, struct

def send_msg(sock, msg):
    send_frame(sock, msg.encode('utf-8'))

def recv_msg(sock):
    return recv_frame(sock).decode('utf-8')

def send_frame(sock, frame):
    frame_size = struct.pack('>i', len(frame))
    sock.sendall(frame_size + frame)

def recv_frame(sock):
    chunk = _recv_loop(sock, struct.calcsize('>i'))
    frame_size = struct.unpack('>i', chunk)[0]
    return _recv_loop(sock, frame_size)

def set_server(sock, host):
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(host)
    sock.listen(5)

def _recv_loop(sock, size):
    frame = b''
    while (len(frame) < size):
        frame_chunk = sock.recv(size - len(frame))
        frame += frame_chunk
    return frame

class TcpSocket:
    def __init__(self, sock=None):
        if not sock:
            self.__init__(socket.socket())
        else:
            self.m_sock = sock

    def __getattr__(self, attr):
        return getattr(self.m_sock, attr)

    def send_msg(self, msg):
        send_msg(self.m_sock, msg)

    def send_frame(self, frame):
        send_frame(self.m_sock, frame)

    def recv_msg(self):
        return recv_msg(self.m_sock)

    def recv_frame(self):
        return recv_frame(self.m_sock)

    def set_server(self, host):
        set_server(self.m_sock, host)

    def serve(self):
        sock, addr = self.m_sock.accept()
        return TcpSocket(sock), addr
