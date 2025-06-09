#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100001

bool validChar(char c) {
    return c == 'C' || c == 'c' || c == 'S' || c == 's' || c == 'Z' || c == 'z';
}

int main(int argc, char** argv) {
    char *inputName = argv[1];
    char *outputName = argv[2];

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    char buffer[MAX_SIZE];

    while(fgets(buffer, MAX_SIZE, input) != NULL) {
        
        for(int i = 0; i < strlen(buffer) -1; i++) {
            if(buffer[i] == '"' && validChar(buffer[i+1])) {
                fprintf(output, "%c", buffer[i+1]);
                i++;
            } else {
                fprintf(output, "%c", buffer[i]);
            }
        }
        fprintf(output, "%c", buffer[strlen(buffer) - 1]);
    }

    fclose(input);
    fclose(output);

    return 0;
}