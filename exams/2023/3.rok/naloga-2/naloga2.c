#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tests/javni/naloga2.h"

int** zmehcaj(int** slika, int n, int m, int d) {

    int **newImg = (int **) calloc((n-2*d), sizeof(int *));
    for(int i = 0; i < (n-2*d); i++) newImg[i] = calloc((m-2*d), sizeof(int));

    int new_height = (n - 2*d);
    int new_width = (m - 2*d);

    for(int i = 0; i < new_height; i++) { 
        for(int j = 0; j < new_width; j++) {
            int counter = 0;
            int avg = 0;
            for(int ix = i; (ix <= (i + 2*d)) && (ix < n); ix++) {
                for(int iy = j; (iy <= (j + 2*d)) && (iy < m); iy++) {
                    avg += slika[ix][iy];
                    counter++;
                }
            }
            int px = avg / counter;
            newImg[i][j] = px;
        }
    }
    return newImg;
}

#ifndef test

int main() {

    return 0;
}

#endif
