#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100000

int main(int argc, char** argv) {
    char *fileName = argv[1];

    FILE* input = fopen(fileName, "rb");

    unsigned char buffer[MAX];

    int read_bytes = fread(buffer, sizeof(unsigned char), MAX, input);

    int counter = 0;

    for(int i = 0; i < read_bytes; i++) {
        unsigned char byte = buffer[i];
        while(byte > 0) {
            if((byte & 1) == 1) counter++;
            byte = byte >> 1;
        }
    }
    printf("%d\n", counter);

    return 0;
}