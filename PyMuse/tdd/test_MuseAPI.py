import pytest
import MuseAPI

@pytest.fixture
def api():
    return MuseAPI.MuseAPI(('localhost', 8888, 9999))

class TestMuseAPI:

    def test_wrong_args_type(self):
        with pytest.raises(TypeError):
            api = MuseAPI.MuseAPI('localhost', 8888, 9999)
        assert True

    def test_wrong_args_address(self):
        with pytest.raises(TypeError):
            api = MuseAPI.MuseAPI((7777, 8888, 9999))
        assert True

    def test_wrong_args_port_comm(self):
        with pytest.raises(TypeError):
            api = MuseAPI.MuseAPI(('localhost', 'localhost', 9999))
        assert True

    def test_wrong_args_port_cmd(self):
        with pytest.raises(TypeError):
            api = MuseAPI.MuseAPI(('localhost', 8888, 'localhost'))
        assert True

    def test_subscribe_success(self, api):
        for key in MuseAPI.Keys:
            api.subscribe(key)
            assert MuseAPI.InstanceName[key] in api.muse.__dict__

    def test_subscribe_failure(self, api):
        for key in MuseAPI.Keys:
            api.subscribe(key)
            assert MuseAPI.InstanceName[key] not in api.muse.__dict__
