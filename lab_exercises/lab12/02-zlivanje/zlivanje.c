#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);

    FILE* inputs[n];

    for(int i = 0; i < n; i++) {
        char fileName[100];
        scanf("%s", fileName);

        inputs[i] = fopen(fileName, "r");
    }
    
    char outputName[100];
    scanf("%s", outputName);
    FILE* output = fopen(outputName, "w");

    int buffer[n];
    int valid[n];

    for(int i = 0; i < n; i++) {
        if(fscanf(inputs[i], "%d", &buffer[i]) == 1) {
            valid[i] = 1;
        } else {
            valid[i] = 0;
        }
    }

    while(true) {
        int minIndx = -1;

        for(int i = 0; i < n; i++) {
            if(valid[i])
                if(minIndx == -1 || buffer[i] < buffer[minIndx]) minIndx = i;
        }

        if(minIndx == -1) break;

        fprintf(output, "%d\n", buffer[minIndx]);

        if(fscanf(inputs[minIndx], "%d", &buffer[minIndx]) != 1) valid[minIndx] = 0; 
    }

    for(int i = 0; i < n; i++) fclose(inputs[i]);
    fclose(output);
    
    return 0;
}