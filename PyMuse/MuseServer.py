import TcpSocket, threading, time, MuseKeys, MuseInfo, Osc, struct

class MuseServerError(Exception):
    pass


class MuseClientThread:
    def __init__(self, token, comm_socket):
        self._token = token
        self._error = None
        self._subscription_lock = threading.RLock()
        self._keys = MuseKeys.MuseKeys
        self._subscribe_list = [False for i in self._keys]
        self._comm_lock = threading.RLock()
        self._comm_socket = comm_socket

    def maj(self, token, cmd_socket):
        if token != self._token:
            return 'FAI TOKEN'
        self._cmd_table = {'SUB':self._subscribe, 'UNS':self._unsubscribe, 'END':self._quit}
        self._cmd_socket = cmd_socket
        self._cmd_thread = threading.Thread(target = self.handler)
        self._cmd_thread.daemon = True
        print 'Success maj client'
        return 'SUC TOKEN'

    def start(self):
        self._cmd_thread.start()

    def handler(self):
        print 'Client Dedied Thread Start'
        while 42:
            if not self._handle_cmd_request():
                break
        self._subscription_lock.acquire()
        self._subscribe_list = [False for i in self._keys]
        self._subscription_lock.release()
        self._comm_lock.acquire()
        self._comm_socket.close()
        self._comm_lock.release()
        print 'Client Dedied Thread Stop'

    def _handle_cmd_request(self):
        try:
            msg = self._cmd_socket.msg_recv()
        except TcpSocket.TcpSocketError as error:
            print error
            return None
        request = msg.split()
        try:
            response = self._cmd_table[request[0]](request)
        except KeyError:
            response = 'FAI UNK'
        try:
            self._cmd_socket.msg_send(response)
        except TcpSocket.TcpSocketError as error:
            print error
            return None
        if request[0] == 'END':
            return None
        return True

    def is_subscribe(self, key):
        if not key in self._keys:
            return False
        self._subscription_lock.acquire()
        ret = self._subscribe_list[key]
        self._subscription_lock.release()
        return ret

    def _subscribe(self, request):
        key = int(request[1])
        self._subscription_lock.acquire()
        if key in self._keys and self._subscribe_list[key] == False:
            response = 'SUC SUB ' + request[1]
            self._subscribe_list[key] = True
        else:
            response = 'FAI SUB ' + request[1]
        self._subscription_lock.release()
        print response
        return response

    def _unsubscribe(self, request):
        key = int(request[1])
        self._subscription_lock.acquire()
        if key in self._keys and self._subscribe_list[key] == True:
            response = 'SUC UNS ' + request[1]
            self._subscribe_list[key] = False
        else:
            response = 'FAI UNS ' + request[1]
        self._subscription_lock.release()
        print response
        return response

    def _quit(self, request):
        print 'SUC END'
        return 'SUC END'

    def comm_send(self, msg):
        self._comm_lock.acquire()
        try:
            self._comm_socket.msg_send(msg)
        except TcpSocket.TcpSocketError as error:
            print error
        self._comm_lock.release()


class MuseClientList:
    def __init__(self):
        self._list = {}
        self._lock = threading.RLock()

    def new(self, token, comm_socket):
        self._lock.acquire()
        self._list[token] = MuseClientThread(token, comm_socket)
        self._lock.release()

    def maj(self, token, cmd_socket):
        try:
            token = int(token)
        except ValueError as error:
            print error
            return 'FAI TOKEN'
        self._lock.acquire()
        ret = self._list[token].maj(token, cmd_socket)
        self._lock.release()
        return ret

    def start(self, token):
        self._lock.acquire()
        if token in self._list:
            self._list[token].start()
        self._lock.release()

    def send_to_subscribers(self, raw_msg):
        osc_msg = Osc.OscUrl(raw_msg)
        path = osc_msg.url
        self._lock.acquire()
        try:
            clients = self.get_subscribers(MuseKeys.MusePathToKey[path])
        except KeyError as error:
            self._lock.release()
            return
        for client in clients:
            client.comm_send(raw_msg)
        self._lock.release()

    def get_subscribers(self, key):
        self._lock.acquire()
        clients = [client for token, client in self._list.iteritems() if self._list[token].is_subscribe(key) == True]
        self._lock.release()
        return clients


class TcpServerThreadBase(threading.Thread):
    def __init__(self, clients, addr='', port=9999):
        self._clients = clients
        try:
            self._socket = TcpSocket.TcpSocketServer(addr, port)
        except TcpSocket.TcpSocketError as error:
            raise MuseServerError(error)
        threading.Thread.__init__(self, target = self.handler)
        self.daemon = True

    def msg_send(self, sock, msg):
        try:
            sock.msg_send(msg)
        except TcpSocket.TcpSocketError as error:
            sock.close()
            print str(error)
            return None
        return True

    def msg_recv(self, sock):
        try:
            msg = sock.msg_recv()
        except TcpSocket.TcpSocketError as error:
            sock.close()
            print str(error)
            return None
        return msg

    def handler(self):
        pass

    def log(self, f, msg):
        f.write(struct.pack('>L%ds' % len(msg), len(msg), msg))


class MuseServerComm(TcpServerThreadBase):
    def handler(self):
        print 'Server Comm Started'
        token_unique_part = 0
        while 42:
            print 'Wait for Comm Connection'
            sock, addr = self._socket.accept()
            print 'Got Comm Connection'
            token = int(time.time()) + token_unique_part
            token_unique_part += 1
            if not self.msg_send(sock, str(token)):
                print 'broken'
                continue
            print token
            self._clients.new(token, sock)

class MuseServerCmd(TcpServerThreadBase):
    def handler(self):
        print 'Server Cmd Started'
        while 42:
            print 'Wait for Cmd Connection'
            sock, addr = self._socket.accept()
            print 'Got Cmd Connection'
            token = self.msg_recv(sock)
            if not token:
                print 'No Token'
                continue
            print 'Token Receive', token
            print repr(token)
            response = self._clients.maj(token, sock)
            self.msg_send(sock, response)
            try:
                self._clients.start(int(token))
            except ValueError as error:
                print error

class MuseServerProd(TcpServerThreadBase):
    def handler(self):
        f = open('Muse.log', 'w')
        print 'Server Prod Started'
        io_sock, io_addr = self._socket.accept()
        print 'Connected to muse IO'
        while 42:
            #raw_data = '/muse/batt\0\0,iiii\0\0\0' + struct.pack('>4i', 0, 1, 2, 3)
            #raw_data = '/muse/elements/blink\0\0\0\0,i\0\0' + struct.pack('>i', 42)
            #raw_data = '/muse/acc\0\0\0,fff\0\0\0\0' + struct.pack('>3f', 0.0, 1.1, 2.2)
            raw_data = self.msg_recv(io_sock)
            if not raw_data:
                break
            self._clients.send_to_subscribers(raw_data)
            self.log(f, raw_data)
            #time.sleep(1)
        print 'Producer : Stop due to MuseIO socket error'
        f.close()

class MuseServer:
    def __init__(self, address='', io_port = 5000, comm_port=5001, cmd_port=5002):
        self._clients = MuseClientList()
        try:
            self._comm_server = MuseServerComm(self._clients, address, comm_port)
            self._cmd_server = MuseServerCmd(self._clients, address, cmd_port)
            self._prod_server = MuseServerProd(self._clients, address, io_port)
        except MuseServerError:
            raise

    def start(self):
        self._prod_server.start()
        time.sleep(0.1)
        self._comm_server.start()
        time.sleep(0.1)
        self._cmd_server.start()
        time.sleep(0.1)

def main():
    try:
        server = MuseServer()
    except MuseServerError as error:
        print 'Main :', str(error)
    else:
        server.start()
        raw_input('Main : Press Enter to Quit\n')

if __name__ == '__main__':
    main()
    print 'Main : Exit'
