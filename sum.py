#!/usr/bin/python3

from random import randrange
import os

for i in range(100):
    a = randrange(
        41720394871239048723902347832412312312312312156236463263462543)
    b = randrange(4172039487123904872390234783241231231312312313)

    if a < b:
        a, b = b, a

    os.system("./a.out "+str(a)+" + "+str(b)+" > test.txt")
    c = a + b
    f = open("test.txt", "r")
    if c != int(f.read()):
        print("error")
        print("a: "+str(a))
        print("b: "+str(b))
        exit()
    else:
        print("Ok")
    f.close()
