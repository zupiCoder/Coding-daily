#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tests/naloga2.h"

int dolzinaCikla(Vozlisce* zacetek) {
    Vozlisce** saved = (Vozlisce**) malloc(1000 * sizeof(Vozlisce*));
    Vozlisce* list = zacetek;
    int i = 0, k = 0;

    while(true) {
        for(int ix = 0; ix < i; ix++) {
            if(list == saved[ix]) {
                k = (i - ix);
                return k;
            }
        }
        saved[i] = list;
        list = list->naslednje;
        i++;
    }
    return k;
}

#ifndef test
int main() {

    return 0;
}
#endif