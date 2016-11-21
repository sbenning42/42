from MyPyLib import TcpSocket

class MuseAPI(object):
    def __init__(self, addr, port_comm, port_cmd):
        self.m_comm = TcpSocket.TcpSocket()
        self.m_cmd = TcpSocket.TcpSocket()
        self.m_comm.connect((addr, port_comm))
        token = self.m_comm.recv_msg()
        self.m_cmd.connect((addr, port_cmd))
        self.m_comm.send_msg(token)
