from MySocket import MySocket
from time import time, sleep

data = ['This Is a A data', 'This Is a B data', 'This Is a C data']
s = MySocket()
s.client(('localhost', 5000))
while 42:
    for d in data:
        s.send(d + str(time()))
