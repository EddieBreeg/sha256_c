#include "sha256.h"
#include <stdio.h>
#include <stdlib.h>


// reads any file and computes the sha256 digest
int main(int argc, char const *argv[])
{
    FILE* f = fopen(argv[1], "rb");
    if(!f)
    {
        printf("Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    byte hash[32];
    sha256_hash_file(f, hash);

    for (size_t i = 0; i < 31; i++)
        printf("%02x:", hash[i]);
    printf("%02x\n", hash[31]);

    return 0;
}
