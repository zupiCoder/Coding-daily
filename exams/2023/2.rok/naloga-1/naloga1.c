#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

int main(int argc, char** argv) {

    char *inputName = argv[1];
    char *outputName = argv[2];

    FILE* input = fopen(inputName, "rb");
    FILE* output = fopen(outputName, "wb");

    unsigned char *buffer = malloc(MAX_SIZE * sizeof(unsigned char));

    int read_bytes = fread(buffer, sizeof(unsigned char), MAX_SIZE, input);

    for(int i = 1; i < read_bytes; i++) {

        if(buffer[i-1] != buffer[i]) {
            fwrite(&buffer[i-1], sizeof(unsigned char), 1, output);
        }
    }
    fwrite(&buffer[read_bytes - 1], sizeof(unsigned char), 1, output);

    free(buffer);
    fclose(input);
    fclose(output);

    return 0;
}