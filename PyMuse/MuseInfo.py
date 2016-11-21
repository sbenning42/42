import Osc, MuseKeys, threading

_MuseChannels = ('chan1', 'chan2', 'chan3', 'chan4')
_MuseEmpty = ('',)

class MuseMsg(Osc.Osc):
    def __init__(self, raw_msg):
        Osc.Osc.__init__(self, raw_msg)
        self.key = MuseKeys.MusePathToKey[self.url]


class IntInfoBase(int):
    def __new__(self, key, args):
        return int.__new__(self, args[0] if args[0] != None else -1)

    def update(self, msg):
        return IntInfoBase(None, msg.args)


class FloatInfoBase(float):
    def __new__(self, key, args):
        return float.__new__(self, args[0] if args[0] != None else 0.0)

    def update(self, msg):
        return FloatInfoBase(None, msg.args)


class StrInfoBase(str):
    def __new__(self, key, args):
        return str.__new__(self, args[0] if args[0] != None else 'null')

    def update(self, msg):
        return StrInfoBase(None, msg.args)


class InfoBase(object):
    def __init__(self, keys, args):
        for key in keys:
            setattr(self, key, None)

    def update(self, msg):
        for k, v in zip(MuseInfo._MuseTable[msg.key][MuseInfo._mt_attrib], msg.args):
            self.__dict__[k] = v
        return self


class MuseInfo(object):
    _MuseTable = {
 0:('ALL'                                       ,''                 ,''                     ,()                 ,()                            ),
 1:('/muse/acc'                                 ,'Acc'              ,'acc'                  ,(InfoBase,)        ,('x', 'y', 'z')               ),
 2:('/muse/batt'                                ,'Batt'             ,'batt'                 ,(InfoBase,)        ,('SoC', 'FGv', 'ADCv', 'temp')),
 3:('/muse/elements/is_good'                    ,'IsGood'           ,'is_good'              ,(InfoBase,)        ,_MuseChannels                 ),
 4:('/muse/eeg'                                 ,'Eeg'              ,'eeg'                  ,(InfoBase,)        ,_MuseChannels                 ),
 5:('/muse/elements/blink'                      ,'Blink'            ,'blink'                ,(IntInfoBase,)     ,_MuseEmpty                    ),
 6:('/muse/elements/jaw_clench'                 ,'JawClench'        ,'jaw_clench'           ,(IntInfoBase,)     ,_MuseEmpty                    ),
 7:('/muse/eeg/quantization'                    ,'Quantization'     ,'quantization'         ,(IntInfoBase,)     ,_MuseEmpty                    ),
 8:('/muse/elements/experimental/concentration' ,'Concentration'    ,'concentration'        ,(FloatInfoBase,)   ,_MuseEmpty                    ),
 9:('/muse/elements/experimental/mellow'        ,'Mellow'           ,'mellow'               ,(FloatInfoBase,)   ,_MuseEmpty                    ),
10:('/muse/elements/low_freqs'                  ,'LowFreqs'         ,'low_freqs'            ,(InfoBase,)        ,_MuseChannels                 ),
11:('/muse/elements/delta_absolute'             ,'DeltaAbs'         ,'delta_abs'            ,(InfoBase,)        ,_MuseChannels                 ),
12:('muse/elements/theta_absolute'              ,'ThetaAbs'         ,'theta_abs'            ,(InfoBase,)        ,_MuseChannels                 ),
13:('/muse/elements/alpha_absolute'             ,'AlphaAbs'         ,'alpha_abs'            ,(InfoBase,)        ,_MuseChannels                 ),
14:('/muse/elements/beta_absolute'              ,'BetaAbs'          ,'beta_abs'             ,(InfoBase,)        ,_MuseChannels                 ),
15:('/muse/elements/gamma_absolute'             ,'GammaAbs'         ,'gamma_abs'            ,(InfoBase,)        ,_MuseChannels                 ),
16:('/muse/elements/delta_relative'             ,'DeltaRel'         ,'delta_rel'            ,(InfoBase,)        ,_MuseChannels                 ),
17:('/muse/elements/theta_relative'             ,'ThetaRel'         ,'theta_rel'            ,(InfoBase,)        ,_MuseChannels                 ),
18:('/muse/elements/alpha_relative'             ,'AlphaRel'         ,'alpha_rel'            ,(InfoBase,)        ,_MuseChannels                 ),
19:('/muse/elements/beta_relative'              ,'BetaRel'          ,'beta_rel'             ,(InfoBase,)        ,_MuseChannels                 ),
20:('/muse/elements/gamma_relative'             ,'GammaRel'         ,'gamma_rel'            ,(InfoBase,)        ,_MuseChannels                 ),
21:('/muse/elements/delta_session_score'        ,'DeltaSsc'         ,'delta_ssc'            ,(InfoBase,)        ,_MuseChannels                 ),
23:('/muse/elements/theta_session_score'        ,'ThetaSsc'         ,'theta_ssc'            ,(InfoBase,)        ,_MuseChannels                 ),
24:('/muse/elements/alpha_session_score'        ,'AlphaSsc'         ,'alpha_ssc'            ,(InfoBase,)        ,_MuseChannels                 ),
25:('/muse/elements/beta_session_score'         ,'BetaSsc'          ,'beta_ssc'             ,(InfoBase,)        ,_MuseChannels                 ),
26:('/muse/elements/gamma_session_score'        ,'GammaSsc'         ,'gamma_ssc'            ,(InfoBase,)        ,_MuseChannels                 ),
27:('/muse/elements/touching_forehead'          ,'TouchingForehead' ,'touching_forehead'    ,(IntInfoBase,)     ,_MuseEmpty                    ),
28:('/muse/elements/horseshoe'                  ,'HorseShoe'        ,'horseshoe'            ,(InfoBase,)        ,_MuseChannels                 ),
29:('/muse/drlref'                              ,'DrlRef'           ,'drlref'               ,(InfoBase,)        ,('drl', 'ref')                ),
30:('/muse/config'                              ,'Config'           ,'config'               ,(StrInfoBase,)     ,_MuseEmpty                    ),
31:('/muse/version'                             ,'Version'          ,'version'              ,(StrInfoBase,)     ,_MuseEmpty                    )
}
    _mt_path = 0
    _mt_class = 1
    _mt_instance = 2
    _mt_parent = 3
    _mt_attrib = 4

    def __init__(self):
        self._table_lock = threading.RLock()

    def instanciate(self, keys):
        self._table_lock.acquire()
        for key in keys:
            Class = type(self._c_name(key), self._c_parent(key), self._c_attrib(key))
            i_name, i_keys = self._i_get(key)
            instance = Class(i_keys, [None for i in i_keys])
            setattr(self, i_name, instance)
        self._table_lock.release()

    def update(self, raw_msg):
        self._table_lock.acquire()
        msg = MuseMsg(raw_msg)
        i_name = self._MuseTable[msg.key][self._mt_instance]
        self.__dict__[i_name] = self.__dict__[i_name].update(msg)
        self._table_lock.release()

    def destroy(self, keys=None):
        self._table_lock.acquire()
        if not keys:
            keys = [k for k in self._MuseTable[1:]]
        for key in keys:
            delattr(self, self._MuseTable[key][self._mt_instance])
        self._table_lock.release()

    def _i_get(self, key):
        return self._MuseTable[key][self._mt_instance], self._MuseTable[key][self._mt_attrib]

    def _c_name(self, key):
        return self._MuseTable[key][self._mt_class]

    def _c_parent(self, key):
        return self._MuseTable[key][self._mt_parent]

    def _c_attrib(self, key):
        return {k:None for k in self._MuseTable[key][self._mt_attrib]}
