#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tests/naloga2.h"

Vozlisce** tabelaSeznamov(int* t, int d, int n) {
    Vozlisce ** start = (Vozlisce**) malloc(n * sizeof(Vozlisce *));

    for(int i = 0; i < n; i++) start[i] = (Vozlisce*) malloc(n * sizeof(Vozlisce));

    Vozlisce** list = start;

    for(int i = 0; i < n; i++) {
        Vozlisce *curr = list[i];

        for(int ind = (1 << i) -1; ind < d; ind += (1 << i)) {
            curr->vTabelo = &t[ind];
            if(ind + (1 << i) < d){
                curr->naslednje = (Vozlisce*) malloc(n * sizeof(Vozlisce));
            } else curr->naslednje = NULL;
            curr = curr->naslednje;
        }
    }
    return start;
}

#ifndef test
int main() {

    return 0;
}
#endif