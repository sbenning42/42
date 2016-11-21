import TcpSocket, MuseKeys, MuseInfo, threading

class MuseClientError(Exception):
    pass

class MuseClientProducer(threading.Thread):
    def __init__(self, muse_info, server_address='localhost', comm_port=5001):
        self._muse_info = muse_info
        self._error = None
        try:
            self._comm_socket = TcpSocket.TcpSocketClient(server_address, comm_port)
            self.token = self._comm_socket.msg_recv()
        except TcpSocket.TcpSocketError as error:
            raise MuseClientError(error)
        threading.Thread.__init__(self, target = self.handler)
        self.daemon = True

    def get_error(self):
        return self._error

    def handler(self):
        while 42:
            try:
                msg = self._comm_socket.msg_recv()
            except TcpSocket.TcpSocketError as error:
                self._error = 'Producer : ' + str(error)
                break
            self._muse_info.update(msg)
        self._comm_socket.close()
        self._muse_info.destroy()


class MuseClient:
    def __init__(self, server_address='localhost', comm_port=5001, cmd_port=5002):
        self._keys = MuseKeys.MuseKeys
        self._subscribe_list = [False for i in self._keys]
        self._muse_info = MuseInfo.MuseInfo()
        self._producer = MuseClientProducer(self._muse_info, server_address, comm_port)
        try:
            self._cmd_socket = TcpSocket.TcpSocketClient(server_address, cmd_port)
            self._cmd_socket.msg_send(self._producer.token)
            token_response = self._cmd_socket.msg_recv()
        except TcpSocket.TcpSocketError as error:
            raise MuseClientError(error)
        if token_response.find('SUC') < 0:
            raise MuseClientError('Controller : Errored TOKEN')

    def start(self):
        self._producer.start()
        
    def stop(self):
        return self._handle_new_request('END')

    def get_error(self):
        return self._producer.get_error()

    def subscribe(self, keys):
        ret = 0
        for key in keys:
            if not key in self._keys or self._subscribe_list[key] == True:
                continue
            request = 'SUB ' + str(key)
            if self._handle_new_request(request):
                self._subscribe_list[key] = True
                self._muse_info.instanciate([key])
                ret += 1
        return ret

    def unsubscribe(self, keys):
        ret = 0
        for key in keys:
            if not key in self._keys or self._subscribe_list[key] == False:
                continue
            request = 'UNS ' + str(key)
            if self._handle_new_request(request) == True:
                self._subscribe_list[key] = False
                self._muse_info.destroy([key])
                ret += 1
        return ret

    def is_subscribe(self, key):
        if not key in self._keys:
            return None
        return self._subscribe_list[key]

    def _handle_new_request(self, request):
        try:
            self._cmd_socket.msg_send(request)
            response = self._cmd_socket.msg_recv()
        except TcpSocket.TcpSocketError as error:
            raise MuseClientError(error)
        return response.find('SUC') > -1
