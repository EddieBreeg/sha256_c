#include "sha256.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    FILE* f = fopen(argv[1], "rb");
    if(!f)
    {
        printf("Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fseek(f, 0, SEEK_END);
    size_t len = ftell(f);
    fseek(f, 0, 0);

    byte *data = malloc(len);
    fread(data, 1, len, f);
    byte hash[32];
    sha256_hash(data, len, hash);

    for (size_t i = 0; i < 31; i++)
        printf("%02x:", hash[i]);
    printf("%02x\n", hash[31]);

    free(data);
    return 0;
}
