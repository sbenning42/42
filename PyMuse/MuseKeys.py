MusePaths = ['ALL',
        '/muse/acc',
        '/muse/batt',
        '/muse/elements/is_good',
        '/muse/eeg',
        '/muse/elements/blink',
        '/muse/elements/jaw_clench',
        '/muse/eeg/quantization',
        '/muse/elements/experimental/concentration',
        '/muse/elements/experimental/mellow',
        '/muse/elements/low_freqs',
        '/muse/elements/delta_absolute',
        'muse/elements/theta_absolute',
        '/muse/elements/alpha_absolute',
        '/muse/elements/beta_absolute',
        '/muse/elements/gamma_absolute',
        '/muse/elements/delta_relative',
        '/muse/elements/theta_relative',
        '/muse/elements/alpha_relative',
        '/muse/elements/beta_relative',
        '/muse/elements/gamma_relative',
        '/muse/elements/delta_session_score',
        '/muse/elements/theta_session_score',
        '/muse/elements/alpha_session_score',
        '/muse/elements/beta_session_score',
        '/muse/elements/gamma_session_score',
        '/muse/elements/touching_forehead',
        '/muse/elements/horseshoe',
        '/muse/drlref',
        '/muse/config',
        '/muse/version']

MuseKeys = range(len(MusePaths))

MusePathToKey = {path : key for key, path in enumerate(MusePaths)}

ACC = 1
BATT = 2
ISGOOD = 3
EEG = 4
BLINK = 5
JAWCLENCH = 6
QUANTIZATION = 7
CONCENTRATION = 8
MELLOW = 9
LOWFREQS = 10
DELTAABS = 11
THETAABS = 12
ALPHAABS = 13
BETAABS = 14
GAMMAABS = 15
DELTAREL = 16
THETAREL = 17
ALPHAREL = 18
BETAREL = 19
GAMMAREL = 20
DELTASSC = 21
THETASSC = 22
ALPHASSC = 23
BETASSC = 24
GAMMASSC = 25
TOUCHING = 26
HORSESHOE = 27
DRLREF = 28
CONFIG = 29
VERSION = 30
