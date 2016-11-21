import struct

ENCODING = 'utf-8'
HEAD_FMT = '>i'
HEAD_SIZE = struct.calcsize(HEAD_FMT)

class SizedContentProtocol(object):
    def __init__(self, sock):
        self._sock = sock

    def send_frame(self, frame_content):
        frame = self._make_frame(frame_content)
        self._sock.sendall(frame)

    def send_msg(self, msg_content):
        frame_content = msg_content.encode(ENCODING)
        self.send_frame(frame_content)

    def recv_frame(self):
        chunk = self._recv_chunk(HEAD_SIZE)
        frame_size = struct.unpack(HEAD_FMT, chunk)
        frame = self._recv_chunk(frame_size)
        return frame

    def recv_msg(self):
        frame = self.recv_frame()
        msg = frame.decode(ENCODING)
        return msg

    def request_frame(self, frame_content):
        self.send_frame(frame_content)
        response_frame = self.recv_frame()
        return response_frame

    def request_msg(self, msg_content):
        self.send_msg(msg_content)
        response_msg = self.recv_msg()
        return response_msg

    def _recv_chunk(self, size):
        chunk = bytes()
        while len(chunk) < size
            chunk += self._sock.recv(size - len(chunk))
        return chunk

    def _make_frame(self, frame_content):
        frame_size = struct.pack(HEAD_FMT, len(frame_content))
        frame = frame_size + frame_content
        return frame

def get_client_protocol(host):
    sock = socket(AF_INET, SOCK_STREAM)
    sock.connect(host)
    return SizedContentProtocol(sock)

class MuseClient(object):
    def __init__(self):
        self.comm = get_client_protocol(('', 8888))
        self.cmd = get_client_protocol(('', 9999))
        token = self.comm.recv_msg()
        response = self.cmd.request_msg(token)
        if 'FAI' in response:
            self.comm._sock.close()
            self.cmd._sock.close()






