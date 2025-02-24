#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

void racionaliziraj(char** nizi) {
    int d = 0;
    char** t = nizi;
    while(*t != NULL) {
        d++; t++;
    }

    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            if(strcmp(nizi[i], nizi[j]) == 0) {
                nizi[j] = nizi[i];
            }
        }
    }
}

#ifndef test
int main() {

    return 0;
}
#endif
