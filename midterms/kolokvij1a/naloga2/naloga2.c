#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {
    int max = 0;
    for(int i = 0; i < stVhodnih; i++) {
        if(strlen(nizi[i]) > max) max = strlen(nizi[i]);
    }

    *stIzhodnih = max;
    char** new_nizi = malloc(max * sizeof(char*));

    for(int j = 0; j < *stIzhodnih; j++) {
        new_nizi[j] = malloc((stVhodnih+1) * sizeof(char));
        int temp_indx = 0;
        for(int i = 0; i < stVhodnih; i++) {
            if(j < strlen(nizi[i])) {
                new_nizi[j][temp_indx] = nizi[i][j];
                temp_indx++;
            }
        }
        new_nizi[j][temp_indx] = '\0';
    }

    return new_nizi;
}

#ifndef test

int main() {
    return 0;
}

#endif
