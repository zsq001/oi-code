from cyaron import *

for i in range(5, 11):
    io = IO(file_prefix="dice", data_id=i)
    T = 200
    io.input_writeln(T)
    while T != 0:
        T -= 1
        n = randint(500000, 1000000)
        io.input_writeln(n)
    io.output_gen("dice.exe")