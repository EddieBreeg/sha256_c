#pragma once

#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned int uint32;


#define ROTR(x,n) ((x>>n) | (x<<(32-n)))

#define Ch(x, y, z) ((x & y) ^ (~x & z))
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

#define SIGMA_0(x) (ROTR(x,  2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA_1(x) (ROTR(x,  6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define sigma_0(x) (ROTR(x,  7) ^ ROTR(x, 18) ^ (x >> 3))
#define sigma_1(x) ((ROTR(x, 17) ^ ROTR(x, 19)) ^ (x >> 10))


#define BIG_ENDIAN(b) ((b[0]<<24) | (b[1]<<16) | (b[2]<<8) | b[3])

typedef struct sha256_context
{
    uint32 block[16];
    uint32 hash[8];
    size_t dataLength;
} sha256_context;


void _init(sha256_context* ctx, size_t length);
void _hash(sha256_context* ctx, void* data);
void _finish(sha256_context* ctx, byte output[32]);


uint32 _pad(byte buffer[128], size_t totalLength);
void _parse(sha256_context* ctx, byte buffer[64]);
void _update(sha256_context* ctx);

void sha256_hash(void* data, size_t len, byte output[32]);