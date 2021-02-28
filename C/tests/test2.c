#include "sha256.h"
#include <stdio.h>
#include <stdlib.h>

void printTab(byte *buffer, int size)
{
    for(int i=0; i<size; i+=16)
    {
        for(int j=0; j<16 && j<size; j++)
            printf("%i ", buffer[i+j]);
        printf("\n");
    }
}
int compare(byte expected[32], byte actual[32])
{
    for(int i=0; i<32; i++)
        if(expected[i] != actual[i]) return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
