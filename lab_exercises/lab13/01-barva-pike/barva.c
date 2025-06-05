#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    
    FILE* input = fopen(argv[1], "rb");

    int row = atoi(argv[2]);
    int col = atoi(argv[3]);
    int width, height;

    char headerLine[10];
    fgets(headerLine, sizeof(headerLine), input);
    fscanf(input,"%d %d\n", &width, &height);
    fgets(headerLine, sizeof(headerLine), input);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            unsigned char R = fgetc(input);
            unsigned char G = fgetc(input);
            unsigned char B = fgetc(input);

            if(i == row && j == col) {
                printf("%d %d %d\n", R, G, B);
                return 0;
            }
        }
    }
    fclose(input);

    return 0;
}