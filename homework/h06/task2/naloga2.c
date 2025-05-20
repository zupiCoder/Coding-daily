#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {

    int **rezultat = calloc(ciljnoStVrstic, sizeof(int*));
    int D = (N * izvornoStVrstic) / ciljnoStVrstic;

    for(int i = 0; i < ciljnoStVrstic; i++) rezultat[i] = calloc(D+1, sizeof(int));

    int ind = 0;
    for(int i = 0; i < izvornoStVrstic; i++) {
        for(int j = 0; j < N; j++) {
            int row = ind / D;
            int col = ind % D;

            rezultat[row][col] = kazalec[i][j];
            ind++;
        }
    }
    return rezultat;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    int D = 0;

    for(int i = 0; i < izvornoStVrstic; i++) {
        for(int j = 0; kazalec[i][j] != 0; j++) D++;
    }
    *ciljnoStVrstic = D / N;
    if(D % N != 0) (*ciljnoStVrstic)++;

    int (*pp2ap)[N] = malloc(*ciljnoStVrstic * sizeof(*pp2ap));

    int ind = 0;
    for(int i = 0; i < izvornoStVrstic; i++) {
        for(int j = 0; kazalec[i][j] != 0; j++) {

            int row = ind / N;            
            int col = ind % (N);

            pp2ap[row][col] = kazalec[i][j];
            ind++;
        }
    }
    return pp2ap;
}

#ifndef test

int main() {

    int* TABELA[] = {
        (int[]) { 7,  0},
        (int[]) { 3, 12, 16,  1,  0},
        (int[]) { 2,  8, 11,  0},
        (int[]) { 5, 13,  9,  0},
        (int[]) {14,  4,  0},
        (int[]) {15,  6, 10,  0},
    };
    int izvornoStVrstic = sizeof(TABELA) / sizeof(TABELA[0]);
    int ciljnoStVrstic = 0;
    int(*rezultat)[N] = pp2ap(TABELA, izvornoStVrstic, &ciljnoStVrstic);

    for (int i = 0;  i < ciljnoStVrstic;  i++) {
        for (int j = 0;  j < N;  j++) {
            printf("%3d", rezultat[i][j]);
        }
        printf("\n");
    }
    free(rezultat);

    return 0;
}
#endif