#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    char *fileName = argv[1];
    int k = atoi(argv[2]);

    FILE *input = fopen(fileName, "rb");

    unsigned char *buffer = malloc(k * sizeof(char));
    int counter = 0;
    int size = 0;

    while (fread(buffer, 1, 1, input) == 1)
    {
        size++;
    }
    rewind(input);

    int nameSize = strlen(fileName) + (size / k);
    int readBytes = 0;

    while((readBytes = fread(buffer, 1, k, input)) != 0) {

        char *outputName = malloc(nameSize * sizeof(char));
        sprintf(outputName, "%s.%d", fileName, counter);

        FILE* output = fopen(outputName, "wb");

        fwrite(buffer, 1, readBytes, output);

        fclose(output);
        free(outputName);

        counter++;
    }

    return 0;
}