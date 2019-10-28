from random import randint
from os import system
n = [0,1000,1000,1000,100000,100000,100000,100000,100000,100000,100000]

def makedata(f,x):
    n = 100000-randint(1,10)
    m = x-randint(1,3)
    k = x-randint(1,3)
    X = randint(1,100)
    f.write("{0} {1} {2}\n".format(n,m,k))
    f.write("{0} {1}\n".format(X,m-randint(1,3)))

    f.write(' '.join([str(randint(1,X)) for a in range(1,m+1)]))
    f.write('\n')
    f.write(' '.join([str(b) for b in range(1,m+1)]))
    f.write('\n')

    f.write(' '.join([str(randint(1,n//2)) for a in range(1,m+1)]))
    f.write('\n')
    f.write(' '.join([str(b) for b in range(1,m+1)]))
    f.write('\n')


for i in range(1,10 + 1):
    with open('sword{0}.in'.format(i),'w') as f:
        makedata(f,n[i])
    system("sword <sword{0}.in >sword{0}.out".format(i))

