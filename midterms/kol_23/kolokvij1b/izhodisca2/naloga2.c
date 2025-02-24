#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** naSredino(char** nizi, int ciljnaDolzina) {
    
    int d = 0;
    char** t = nizi;
    
    while(*t != NULL) {
        d++; t++;
    }

    char** new_nizi = (char**)malloc((d+1)* sizeof(char*));

    for(int i = 0; i < d; i++) {
        new_nizi[i] = malloc((ciljnaDolzina+1) * sizeof(char));
        int numDots = (ciljnaDolzina - strlen(nizi[i])) / 2;

        for(int j = 0; j < numDots; j++) new_nizi[i][j] = '.';

        strcat(new_nizi[i], nizi[i]);

        for(int x = strlen(new_nizi[i]); x < ciljnaDolzina; x++) new_nizi[i][x] = '.';
        new_nizi[i][ciljnaDolzina] = '\0';
    }
    new_nizi[d] = NULL;

    return new_nizi;
}

#ifndef test

int main() {
    
    return 0;
}

#endif