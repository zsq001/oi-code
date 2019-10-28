from random import randint
from os import system
n = [0,1000,1000,1000,1000,10000,10000,500000,500000,500000,500000]

def makedata(f,x):
    n = randint(1,x)
    m = randint(1,x)
    k = randint(1,n*m)
    f.write("{0} {1} {2}".format(n,m,k))

for i in range(1,10 + 1):
    with open('num{0}.in'.format(i),'w') as f:
        makedata(f,n[i])
    system("num <num{0}.in >num{0}.out".format(i))

