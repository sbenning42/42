import string, math, struct

class OscError(Exception):
    pass


class Osc:
    def __init__(self, raw_msg):
        self._init_private(raw_msg)
        self.url = self._readstring()
        self.typetag = self._readstring()
        parse = {'i':self._readint, 'f':self._readfloat, 's':self._readstring}
        try:
            self.args = [parse[tag]() for tag in self.typetag[1:]]
        except KeyError as error:
            raise OscError('OscError : ' + str(error))

    def _init_private(self, raw_msg):
        if not raw_msg or len(raw_msg) == 0:
            raise OscError('OscError : Empty message')
        self._raw_msg = raw_msg
        self._intsize = struct.calcsize('>i')
        self._floatsize = struct.calcsize('>f')

    def _readint(self):
        if len(self._raw_msg) < self._intsize:
            raise OscError('OscError : To few bytes for int : ' + self._raw_msg)
        value = struct.unpack('>i', self._raw_msg[:self._intsize])[0]
        self._go_next_bloc(self._intsize)
        return value

    def _readfloat(self):
        if len(self._raw_msg) < self._floatsize:
            raise OscError('OscError : To few bytes for float :' + self._raw_msg)
        value = struct.unpack('>f', self._raw_msg[:self._floatsize])[0]
        self._go_next_bloc(self._floatsize)
        return value

    def _readstring(self):
        length = string.find(self._raw_msg, '\0')
        if length < 0:
            raise OscError('OscError : To few bytes for string : ' + self._raw_msg)
        value = self._raw_msg[:length]
        self._go_next_bloc(length + 1)
        return value

    def _go_next_bloc(self, length):
        if not length % 4:
            self._raw_msg = self._raw_msg[length:]
        else:
            self._raw_msg = self._raw_msg[int(math.ceil(length / 4.0) * 4):]


class OscUrl(Osc):
    def __init__(self, raw_msg):
        self._init_private(raw_msg)
        self.url = self._readstring()
