#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    char *fileName = argv[1];
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);

    FILE *input = fopen(fileName, "rb");

    int first_byte = p / 8;
    int last_byte = q / 8;
    if (q % 8 != 0)
        last_byte++;

    int SIZE = (last_byte * 8);
    int *arr = calloc(SIZE, sizeof(int));

    fseek(input, first_byte, SEEK_CUR);

    int start_offset = p % 8;
    int index = 0;

    while (first_byte <= last_byte)
    {

        unsigned char buffer;
        fread(&buffer, 1, 1, input);

        for (int i = 7; i >= 0; i--)
        {
            int bit = (buffer >> i) & 1;
            arr[index] = bit;
            index++;
        }

        first_byte++;
    }

    for (int i = start_offset; i < start_offset + (q - p); i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    fclose(input);

    return 0;
}