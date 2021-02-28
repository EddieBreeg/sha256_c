#include <stdio.h>
#include <stdlib.h>
#include "../src/sha256.h"

#define MAX_SIZE 128

void printTab(byte *buffer, int size)
{
    for(int i=0; i<size; i+=16)
    {
        for(int j=0; j<16 && j<size; j++)
            printf("%02x ", buffer[i+j]);
        printf("\n");
    }
}
int compare(byte expected[32], byte actual[32])
{
    for(int i=0; i<32; i++)
        if(expected[i] != actual[i]) return i;
    return -1;
}

/* reads n randomly generated test vectors from a first file,
and the n corresponding hashes in a second file. Then performs the sha256_hash
function on each vector and compares the result against the expected hash */
int main(int argc, char const *argv[])
{
    FILE* inFile = fopen(argv[2], "rb");
    FILE* hFile = fopen(argv[3], "rb");
    if (!inFile)
    {
        printf("Failed to open file %s: exiting\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    else if (!hFile)
    {
        printf("Failed to open file %s: exiting\n", argv[3]);
        exit(EXIT_FAILURE);
    }
    

    byte data[MAX_SIZE];
    byte expected[32], actual[32];

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        fread(data, 1, i+1, inFile);
        fread(expected, 1, 32, hFile);
        sha256_hash(data, i+1, actual);
        if(compare(expected, actual) != -1)
        {
            printf("Error in hash %i. Expected:\n", i);
            printTab(expected, 32);
            printf("Got:\n");
            printTab(actual, 32);
            printf("Exiting.\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("Success!\n");
    fclose(inFile); fclose(hFile);
    return 0;
}
