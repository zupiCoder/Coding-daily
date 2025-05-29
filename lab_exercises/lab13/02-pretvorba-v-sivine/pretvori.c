#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char izracunajSivino(unsigned char R, unsigned char G, unsigned char B) {
    return (30*R + 59*G + 11*B) / 100;
}

int main(int argc, char **argv) {

    char headerLine[10];
    int numberLine;

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    int width, height;

    fgets(headerLine, sizeof(headerLine), input); //P5
    fscanf(input,"%d %d\n", &width, &height);//sirina visina
    fscanf(input, "%d\n", &numberLine); //255

    fputs(headerLine, output);
    fprintf(output, "%d %d\n", width, height);
    fprintf(output, "%d\n", numberLine);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            unsigned char R = fgetc(input);
            unsigned char G = fgetc(input);
            unsigned char B = fgetc(input);

            unsigned char grayed = izracunajSivino(R , G, B);
            fputc(grayed, output);
        }
    }
    fclose(input);
    fclose(output);

    return 0;
}