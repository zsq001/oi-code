from cyaron import *

for i in range(4, 11):
    io = IO(file_prefix="box", data_id=i)
    T = 500
    io.input_writeln(T)
    while T != 0:
        T -= 1
        n = randint(700, 1000)
        io.input_writeln(n)
        for j in range(0, n):
            io.input_write(randint(-10**3, 10**3))
        io.input_writeln()
        
    io.output_gen("box.exe")