# sha256 C

## Header

[sha256.h](src/sha256.h) contains definitions for the `sha256_context` struct, a few macros, type definitions and most importantly the `sha256_hash` function.

### Types and macros

- `byte`: an 8-bits unsigned integer
- `uint32`: a 32-bits unsigned integer
- `ROTR(x, n)`: rotates x (`uint32`) by n bits to the right
- `BIG_ENDIAN(b)`: converts b (`byte[4]`) to a big-endian encoded `uint32`
- `sha256_context`: a structure that contains everything the algorithm needs to keep track of, namely the data length (64 bits unsigned), the internal state (`uint32[8]`) and the data block (`uint32[16]`).

### Functions

```C
void sha256_hash(const void* data, size_t len, byte output[32])
```
Hashes the data buffer and copies the result into the output buffer.

## Examples and tests

There are a few programs you can use in the [tests](tests) folder in order to ensure the implementation
is working as it should be.

### test.c & gen.py

This program reads n pseudo random vectors, hashes each one and compares the result against the reference hashes 
(computed with python).

First, generate the test vectors and the corresponding hashes:\
```bash
$ ./tests/gen.py <n>
```
where `n` is an integer between 1 and 256.

Then compile and run the test program:\
```bash
$ make test1
$ ./bin/test <n> inputs.in hashes.hash
```

### test2.c

Computes the sha256 digest of any file passed as an argument.

### test3.c

Performs the sha256 hash algorithm on two examples from the sha256 specification (which you 
can find [here](https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf)).

The first example is the message "abc" which, once hashed, should give us the following digest:\
`ba:78:16:bf:8f:01:cf:ea:41:41:40:de:5d:ae:22:23:b0:03:61:a3:96:17:7a:9c:b4:10:ff:61:f2:00:15:ad`

The second example is the message "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq" and should give us:\
`24:8d:6a:61:d2:06:38:b8:e5:c0:26:93:0c:3e:60:39:a3:3c:e4:59:64:ff:21:67:f6:ec:ed:d4:19:db:06:c1`