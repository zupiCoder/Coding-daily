#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 3

int main()
{
    char inputName[21];
    char outputName[21];
    char BUFFER[BUFFER_SIZE];
    int n;

    scanf("%s", inputName);
    scanf("%d", &n);
    scanf("%s", outputName);

    FILE *input = fopen(inputName, "rb");
    FILE *output = fopen(outputName, "w");

    unsigned char R, G, B;

    int counter_R = 0, counter_G = 0, counter_B = 0;

    for (int i = 0; i < n; i++)
    {

        fread(BUFFER, sizeof(unsigned char), BUFFER_SIZE, input);

        R = BUFFER[0];
        G = BUFFER[1];
        B = BUFFER[2];

        if (R > 0 && G == 0 && B == 0)
            counter_R++;
        if (R == 0 && G > 0 && B == 0)
            counter_G++;
        if (R == 0 && G == 0 && B > 0)
            counter_B++;
    }
    fprintf(output, "%d\n%d\n%d", counter_R, counter_G, counter_B);

    fclose(input);
    fclose(output);

    return 0;
}