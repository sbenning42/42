def i__new__(self, dic):
    return  int.__new__(self, dic['val'])

def f__new__(self, dic):
    return float.__new__(self, dic['val'])

def c__init__(self, dic):
    for k,v in dic.iteritems():
        setattr(self, k, v)

obj = type('Blink', (int, ), {'__new__' : int__new__})({'val':42})
print int_t
