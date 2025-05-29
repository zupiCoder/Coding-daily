#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char inputName[21];
    char outputName[21];
    int numBytes;

    scanf("%s", inputName);
    scanf("%d\n", &numBytes);
    scanf("%s", outputName);

    FILE *input = fopen(inputName, "rb");
    FILE *output = fopen(outputName, "w");

    for (int i = 0; i < numBytes; i++)
    {
        unsigned char buffer = fgetc(input);

        fprintf(output, "%02X", buffer);

        if(i < (numBytes - 1)) fputc('\n', output);
    }

    fclose(input);
    fclose(output);

    return 0;
}