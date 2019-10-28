from random import randint
from os import system
n = [0,10,10,10,10000,10000,10000,10**18,10**18,10**18,10**18]

def makedata(f,x):
    dat = randint(1,x)
    f.write(str(dat))

for i in range(1,10 + 1):
    with open('tree{0}.in'.format(i),'w') as f:
        makedata(f,n[i])
    system("std <tree{0}.in >tree{0}.out".format(i))

