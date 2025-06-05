#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

int main(int argc, char *argv[]) {

    char *buffer = malloc(SIZE * sizeof(char));
    char *s = malloc(SIZE * sizeof(char));

    FILE* fp = fopen("input.txt", "r");

    if(fp == NULL) return 0;

    while(fgets(buffer, SIZE, fp)) {
        if(strlen(buffer) > strlen(s)) strcpy(s, buffer);
    }

    FILE* output = fopen("naj.txt", "w");

    fputs(s, output);

    fclose(fp);
    fclose(output);
    
    return 0;
}