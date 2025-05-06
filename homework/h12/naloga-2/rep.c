#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 11

int main(int argc, char *argv[]) {
    int n = atoi(argv[2]);
    FILE* input = fopen(argv[1], "r");

    int lineCount = 0;
    int index = lineCount % n;

    char **buffer = (char **) malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++) buffer[i] = (char *) malloc(MAX_LEN * sizeof(char));

    while(fgets(buffer[index], MAX_LEN, input)) {
        lineCount++;
        index = lineCount % n;
    }
    int offset = lineCount % n;

    if(lineCount < n) 
        for(int i = 0; i < (lineCount); i++) {
            printf("%s", buffer[i]);
        }
    if(lineCount >= n)
        for(int i = 0; i < n; i++) {
            int index = (i + offset) % n;
            printf("%s", buffer[index]);
        }
    for(int i = 0; i < n; i++) free(buffer[i]);
    free(buffer);
    fclose(input);

    return 0;
}