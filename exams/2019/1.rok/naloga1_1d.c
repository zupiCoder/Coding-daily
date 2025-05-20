#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001

int main() {

    char inputName[21];
    char outputName[21];
    char C;

    scanf("%s\n%s\n%c", inputName, outputName, &C);

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    char buffer[MAX_SIZE] = "";
    char readString[MAX_SIZE] = "";

    while(fgets(readString, MAX_SIZE, input)) {
        if(strchr(readString, C) != NULL) 
            strcpy(buffer, readString);
    }
    
    fputs(buffer, output);

    fclose(input);
    fclose(output);

    return 0;
}