import pytest, struct
from mock import patch, call
from MuseAPI import *

class TestMuseAPI:
    @patch('MuseAPI.TcpSocket.TcpSocket')
    def test_socket(self, patched):
        muse_api = MuseAPI('localhost', 8888, 9999)
        assert patched.call_args_list == [(), ()]

    @patch.object(TcpSocket.TcpSocket, 'connect', create=True)
    @patch.object(TcpSocket.TcpSocket, 'send_msg')
    @patch.object(TcpSocket.TcpSocket, 'recv_msg')
    def test_connect(self, foo, bar, connect):
        expected = [call(('localhost', 8888)), call(('localhost', 9999))]
        muse_api = MuseAPI('localhost', 8888, 9999)
        assert connect.call_args_list == expected

    @patch.object(TcpSocket.TcpSocket, 'connect', create=True)
    @patch.object(TcpSocket.TcpSocket, 'send_msg')
    @patch.object(TcpSocket.TcpSocket, 'recv_msg')
    def test_token_exchange(self, recv_msg, send_msg, connect):
        token = '0123456789'
        recv_msg.return_value = token
        muse_api = MuseAPI('localhost', 8888, 9999)
        recv_msg.assert_called_once()
        send_msg.assert_called_once_with(token)

    def test_subscribe(self):
        muse_api = MuseAPI('localhost', 8888, 9999)
        ret = muse_api.subscribe([BLINK, ISGOOD])
        assert ret == 2
        send_msg.call_args_list == expected_send
        recv_msg.call_args_list == expected_send
