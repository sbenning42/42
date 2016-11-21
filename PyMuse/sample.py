from MyPyLib import TcpSocket, Osc

try:
    o = Osc.OscMsg(b'Hello world')
except Osc.OscError as err:
    print(err)
