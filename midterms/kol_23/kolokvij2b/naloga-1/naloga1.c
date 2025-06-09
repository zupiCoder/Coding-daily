
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100000

int main(int argc, char** argv) {

    char *inputName = argv[1];
    char * outputName = argv[2];

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    char buffer[MAX_SIZE];

    while(fgets(buffer, MAX_SIZE, input) != NULL) {
        bool startSpaces = true;

        for(int i = 0; i < strlen(buffer); i++) {
            if(buffer[i] == ' ' && startSpaces) continue;

            if(buffer[i] != ' ') startSpaces = false;

            fprintf(output, "%c", buffer[i]);
        }
    }

    alternative(input, output, buffer);

    return 0;
}