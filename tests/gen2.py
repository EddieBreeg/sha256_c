from hashlib import sha256
from random import randbytes
from sys import argv

# generates n random bytes, and computes the hash 
# then writes both the vector and the hash in two separate files

b = randbytes(int(argv[1]))
h = sha256(b).digest()


print(list(b))
print(list(h))