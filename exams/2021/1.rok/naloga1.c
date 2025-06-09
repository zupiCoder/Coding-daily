#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char inputName[101];
    scanf("%s", inputName);

    FILE* input = fopen(inputName, "rb");

    unsigned char buffer[10];

    int read_bytes = fread(&buffer, sizeof(unsigned char), 8, input);

    if(read_bytes > 2) printf("%d\n", 1);
    else printf("%d\n", 0);

    return 0;
}