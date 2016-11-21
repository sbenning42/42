ACC = 1
EEG = 2
END = 3

Keys = range(END)
InstanceName = {ACC : 'acc', EEG : 'eeg'}

class MuseAPI(object):
    
    def __init__(self, hosts):
        self.muse = None

    def subscribe(self, key):
        pass
