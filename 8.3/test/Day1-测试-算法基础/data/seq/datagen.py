from random import randint
from os import system
n = [0,5,5,5,5,200000,200000,200000,200000,200000,200000]
a = [0,5,5,5,5,10000,10000,10000,10000,10000,10000]

def makedata(f,x,y):
    n = x-randint(0,1)
    
    f.write("{0}\n".format(n))
    f.write(' '.join([str(randint(-y,y)) for i in range(1,n+1)]))


for i in range(1,10 + 1):
    with open('seq{0}.in'.format(i),'w') as f:
        makedata(f,n[i],a[i])
    system("seq <seq{0}.in >seq{0}.out".format(i))

