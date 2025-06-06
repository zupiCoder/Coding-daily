#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char** argv) {

    char* firstInputName = argv[1];
    char* secInputName = argv[2];
    char* outputName = argv[3];

    FILE* firstInput = fopen(firstInputName, "rb");
    FILE* secInput = fopen(secInputName, "rb");
    FILE* output = fopen(outputName, "wb");

    unsigned char firstBuffer[MAX_SIZE];
    unsigned char secBuffer[MAX_SIZE];

    int read_first = fread(firstBuffer, sizeof(unsigned char), MAX_SIZE, firstInput);
    int read_sec = fread(secBuffer, sizeof(unsigned char), MAX_SIZE, secInput);

    int counter = 0;
    int indicate = 0;

    for(int i = 0; i < min(read_first, read_sec); i++) {
        unsigned char byte = max(firstBuffer[i], secBuffer[i]);
        fwrite(&byte, sizeof(unsigned char), 1, output);
        counter++;
    }

    if(read_first > read_sec) indicate = 1;

    for(int i = counter; i < max(read_first, read_sec); i++) {
        if(indicate == 1) {
            fwrite(&firstBuffer[i], sizeof(unsigned char), 1, output);
        } else fwrite(&secBuffer[i], sizeof(unsigned char), 1, output);
    }

    fclose(firstInput);
    fclose(secInput);
    fclose(output);

    return 0;
}