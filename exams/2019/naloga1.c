#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001

int main(int argc, char *argv[]) {

    char inputName[21];
    char outputName[21];
    char C;

    scanf("%s", inputName);
    scanf("%s", outputName);
    scanf(" %c", &C); 
    //skip the last whitespace, pick up the actual char

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");

    char buffer[MAX_SIZE][MAX_SIZE];
    int i = 0;

    while(fgets(buffer[i], MAX_SIZE, input)) i++;

    for(size_t indx = i; indx >= 0; indx--) {
        if(strchr(buffer[indx], C) != NULL) {
            fputs(buffer[indx], output);
            break;
        }
    }
    return 0;
}