#!/usr/bin/python3

import sys

if len(sys.argv) < 4:
    print("Usage: xor.py INPUT OUTPUT KEY")
    exit(1)

f = open(sys.argv[1], 'rb')
g = open(sys.argv[2], 'wb')
x = int(sys.argv[3])

for i in f.read():
    g.write( bytes( [i ^ x] ) )

g.close()
f.close()
