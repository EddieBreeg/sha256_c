from hashlib import sha256
from random import randbytes
from sys import argv

# generates n random test vectors, and computes the hash for each
# then writes both the vector and the hash in two separate files

f1 = open("inputs.in", "wb")
f2 = open("hashes.hash", "wb")

for i in range(int(argv[1])):
    b = randbytes(i+1)
    h = sha256(b).digest()
    f1.write(b)
    f2.write(h)

f1.close()
f2.close()