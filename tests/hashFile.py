from hashlib import sha256
from sys import argv

with open(argv[1], 'rb') as f:
    data = f.read()
    h = sha256(data).digest()

print(["%02x " % b for b in h])