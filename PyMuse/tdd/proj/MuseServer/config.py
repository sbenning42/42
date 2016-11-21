IP_SERVER = ''
IP = 'localhost'
IO_PORT = 5000
COM_PORT = 5001

ACC = 0
EEG = 1
IS_GOOD = 2
BLINK = 3

MuseTable = {
        0 : {'path' : '/muse/acc',              'args' : {'x' : float, 'y' : float, 'z' : float},                   'freq' : 50},
        1 : {'path' : '/muse/eeg',              'args' : {'c1' : float, 'c2' : float, 'c3' : float, 'c4' : float},  'freq' : 220},
        2 : {'path' : '/muse/elements/is_good', 'args' : {'c1' : int, 'c2' : int, 'c3' : int, 'c4' : int},          'freq' : 10},
        3 : {'path' : '/muse/elements/blink',   'args' : int,                                                       'freq' : 10}
        }
