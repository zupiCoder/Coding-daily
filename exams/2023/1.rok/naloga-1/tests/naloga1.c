#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BYTES 100000

int main(int argc, char** argv) {

    char* inputName = argv[1];
    char* outputName = argv[2];

    FILE* input = fopen(inputName, "rb");
    FILE* output = fopen(outputName, "wb");

    unsigned char buffer[MAX_BYTES];
    int index = 0;

    while(fread(&buffer[index], 1, 1, input) != 0) {
        index++;
    };

    unsigned char buffer_output[MAX_BYTES];
    int ind = 0;

    for(int i = 0; i < index; i++) {
        if(buffer[i] == 0x1B && buffer[i+1] == 0xC9) {
            unsigned char c = 0xC9;
            buffer_output[ind] = c;
            ind++;
            i++;
        } else {
            buffer_output[ind] = buffer[i];
            ind++;
        }
    }
    fwrite(buffer_output, sizeof(unsigned char), ind, output);

    fclose(input);
    fclose(output);

    return 0;
}