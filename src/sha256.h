#pragma once

#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned int uint32;


#define ROTR(x,n) ((x>>n) | (x<<(32-n)))

#define BIG_ENDIAN(b) ((b[0]<<24) | (b[1]<<16) | (b[2]<<8) | b[3])

typedef struct sha256_context
{
    uint32 block[16];
    uint32 hash[8];
    size_t dataLength;
} sha256_context;

void sha256_hash(const void* data, size_t len, byte output[32]);