import Osc, struct, MuseInfo, MuseKeys

class MuseMsg(Osc.Osc):
    def __init__(self, raw_msg):
        Osc.Osc.__init__(self, raw_msg)
        self.key = MuseKeys.MusePathToKey[self.url]


class IntInfoBase(int):
    def __new__(self, key, args):
        if args[0] == None:
            arg = -1
        else:
            arg = args[0]
        return int.__new__(self, arg)

    def update(self, msg):
        return IntInfoBase(None, msg.args)


class FloatInfoBase(float):
    def __new__(self, key, args):
        if args[0] == None:
            arg = 0.0
        else:
            arg = args[0]
        return float.__new__(self, arg)

    def update(self, msg):
        return FloatInfoBase(None, msg.args)


class StrInfoBase(str):
    def __new__(self, key, args):
        if args[0] == None:
            arg = ''
        else:
            arg = args[0]
        return str.__new__(self, arg)

    def update(self, msg):
        return StrInfoBase(None, msg.args)


class InfoBase(object):
    def __init__(self, key, args):
        for k in key:
            setattr(self, k, None)

    def update(self, msg):
        for k, v in zip(M_TABLE[msg.key][M_ATTRIB], msg.args):
            self.__dict__[k] = v
        return self


M_TABLE = {
        0 : ('/muse/acc', 'Acc', 'acc', (InfoBase, ), ('x', 'y', 'z')),
        1 : ('/muse/eeg', 'Eeg', 'eeg', (InfoBase, ), ('channel1', 'channel2', 'channel3', 'channel4')),
        2 : ('/muse/blink', 'Blink', 'blink', (IntBase, ), ('None',))
        }

M_SATTRIB = 5

class MuseInfo(object):
    def instanciate(self, keys):
        for key in keys:
            c_name = M_TABLE[key][M_CLASS]
            c_parent = M_TABLE[key][M_PARENT]
            c_attrib = {k:None for k in M_TABLE[key][M_ATTRIB]}
            i_name = M_TABLE[key][M_INSTANCE]
            i_keys = M_TABLE[key][M_ATTRIB]
            i_args = [None for i in i_keys]
            instance = type(c_name, c_parent, c_attrib)(i_keys, i_args)
            setattr(self, i_name, instance)

    def update(self, raw_msg):
        msg = MuseMsg(raw_msg)
        self.__dict__[M_TABLE[msg.key][M_INSTANCE]] = self.__dict__[M_TABLE[msg.key][M_INSTANCE]].update(msg)

    def destroy(self, keys):
        for key in keys:
            delattr(self, M_TABLE[key][M_INSTANCE])



raw = [raw_acc, raw_eeg, raw_blink]
muse = MuseInfo()
muse.instanciate([0, 1, 2])
put(muse)

for r in raw:
    muse.update(r)

put(muse)
muse.destroy([0, 1, 2])
