from os import system
from random import randint

def make(f,n,m):
    f.write('{0} {1}\n'.format(n,m))
    for i in range(m):
        x1 = randint(1,5)
        x2 = randint(n-5,n)
        y1 = randint(1,5)
        y2 = randint(n-5,n)
        f.write('{0} {1} {2} {3}\n'.format(x1,y1,x2,y2))

n = [0,50,50,1000,1000,1000,1000,1000,1000,1000,1000]
m = [0,98,99,99996,99996,99996,99996,99997,99998,99999,100000]

for i in range(1,11):
    with open('carpet{0}.in'.format(i),'w') as f:
        make(f,n[i],m[i])
    system('carpet.exe < carpet{0}.in > carpet{0}.out'.format(i))
