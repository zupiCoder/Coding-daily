#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001

void razlike(FILE *prva, FILE *druga, FILE *izhod)
{

    char buffer_1[SIZE];
    char buffer_2[SIZE];

    int row = 1;

    while (fgets(buffer_1, SIZE, prva) != NULL && fgets(buffer_2, SIZE, druga) != NULL)
    {
        if (strcmp(buffer_1, buffer_2) != 0)
            fprintf(izhod, "%d\n", row);
        row++;
    }
}

int main()
{

    FILE *prva = fopen("prva.txt", "r");
    FILE *druga = fopen("druga.txt", "r");
    FILE *izhod = fopen("izhod.txt", "w");

    razlike(prva, druga, izhod);

    fclose(prva);
    fclose(druga);
    fclose(izhod);

    izhod = fopen("izhod.txt", "r");
    char vrstica[1001];
    printf("Razlicne vrstice:\n");
    while (fgets(vrstica, 1001, izhod)) {
        printf("%s", vrstica);
    }
    fclose(izhod);

    return 0;
}