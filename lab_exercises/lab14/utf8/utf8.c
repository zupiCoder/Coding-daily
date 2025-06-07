#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

int main(int argc, char** argv) {

    char *inputName = argv[1];
    char* outputName = argv[2];

    unsigned char buffer[2*MAX_SIZE];
    short convertedBuffer[MAX_SIZE];

    FILE* input = fopen(inputName, "rb");
    FILE* output = fopen(outputName, "wb");

    int read_bytes = fread(&buffer, sizeof(unsigned char), 2*MAX_SIZE, input);
    int largeSize = 0;
    int ind = 0;

    for(int i = 0; i < read_bytes; i++) {
        short convertedChar = 0;

        if(largeSize == 1) {
            unsigned char byte1 = buffer[i-1]; //5 least significant bits
            unsigned char byte2 = buffer[i]; //6 least significant bits
            convertedChar = ((byte1 & 0x1F) << 6) | (byte2 & 0x3F);

            convertedBuffer[ind++] = convertedChar;
            largeSize = 0;
            continue;
        }
        //bitwise comparison nebo enak 1 saj buffer[i] neko stevilo in 1 << 7 == 128, zato nebo enak 1 razen ko buffer[i] == 128
        if ((buffer[i] & (1 << 7)) != 0) {
            largeSize = 1;
        } else {
            convertedChar = buffer[i];
            convertedBuffer[ind++] = convertedChar;
        }
    }
    fwrite(&convertedBuffer, sizeof(short), ind, output);

    fclose(input);
    fclose(output);

    return 0;
}