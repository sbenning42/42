import pytest
from MuseServer import *
from MuseServer.TcpSocket import *

class TestTcpSocket(object):
    
    def test_client(self, mocker):
        conn = mocker.patch('MuseServer.TcpSocket.socket.connect')
        TcpSocket().client(('localhost', 5000))
        conn.assert_called_once_with(('localhost', 5000))

    def test_client_failure(self):
        with pytest.raises(error) as err:
            TcpSocket().client(('localhost', 5000))
        assert '111' in str(err.value)

    def test_client_param_failure(self):
        with pytest.raises(TypeError) as err:
            TcpSocket().client(('localhost', '5000'))
        assert 'Type' in str(err.value)
