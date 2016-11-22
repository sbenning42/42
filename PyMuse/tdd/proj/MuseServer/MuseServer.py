from TcpSocket import TcpSocket, error
from threading import Thread
from Osc import OscPath
from Config import *

def dispatch(clients, frame):
    key = get_key_from_path(OscPath(frame).path)
    if key < 0:
        return
    subscribers = [c['tcpsock'] for c in clients if key in c['sub']]
    for tcpsock in subscribers:
        tcpsock.send(frame)

def com_handler(clients):
    tcpsock = TcpSocket()
    tcpsock.server((IP_SERVER, COM_PORT))
    io_tcpsock, addr = tcpsock.accept()
    print('Connection MuseIO', addr)
    while 42:
        try:
            frame = io_tcpsock.recv()
        except error as err:
            print(err)
            break
        dispatch(clients, frame)
    io_tcpsock.close()
    print('Com Handler Stop')

def handle_request(req, sub_set):
    if req not in MuseTable:
        return False
    if req in sub_set:
        sub_set.remove(req)
    else:
        sub_set.add(req)
    return True

def client_handler(client):
    tcpsock = client['tcpsock']
    while 42:
        try:
            req = int(tcpsock.recv_ascii())
        except error as err:
            print(err)
            break
        if not handle_request(req, client['sub']):
            break
    tcpsock.close()
    print('Client Handler Stop')
 
def start_thread(handler, *args):
    thread = Thread(target=handler, args=args)
    thread.daemon = True
    thread.start()       

def cmd_handler(clients):
    tcpsock = TcpSocket()
    tcpsock.server((IP_SERVER, CMD_PORT))
    while 42:
        client_tcpsock, addr = tcpsock.accept()
        print('Connection Client', addr)
        client = {'tcpsock' : client_tcpsock, 'sub' : set()}
        clients.append(client)
        start_thread(client_handler, client)

def main():
    clients = list()
    start_thread(com_handler, clients)
    start_thread(cmd_handler, clients)
    input('Press Enter to Quit\n')

if __name__ == '__main__':
    main()
