#include "sha256.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>


void fromFile(const char* path, byte hash[32])
{
    FILE* f = fopen(path, "rb");
    if(!f)
    {
        printf("Error opening %s: %s\n", path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    sha256_hash_file(f, hash);
}
void fromString(const char* string, byte hash[32])
{
    sha256_hash(string, strlen(string), hash);
}
void help()
{
    printf("Usage: \n");
    printf("sha256 [options] input\n\n");
    printf("Options:\n");
    printf("-h: Show this help\n");
    printf("-f: input is a file to read from\n");
    printf("-U: Use UPPERCASE format\n");

    exit(EXIT_SUCCESS);
}
void (*options[])(const char*, byte*) = {fromString, fromFile};

int main(int argc, char const *argv[])
{
    int format = 0;
    int func = 0;
    byte hash[32];

    if(argc < 2) help();
    for (int i = 1; i < argc && *argv[i] == '-'; i++)
    {
        for (int j = 1; j < strlen(argv[i]); j++)
        {
            if(argv[i][j] == 'h') help();
            format += argv[i][j] == 'U';
            func |= argv[i][j] == 'f';
        }
    }
    options[func](argv[argc-1], hash);
    // sha256_hash(argv[argc-1], strlen(argv[argc-1]), hash);

    for (int i = 0; i < 32; i++)
        printf(format?"%02X":"%02x", hash[i]);
    printf("\n");
    
    return 0;
}
