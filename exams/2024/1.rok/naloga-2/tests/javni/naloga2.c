#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "naloga2.h"

void obdelaj(Vozlisce* zacetek, int k) {

    Vozlisce* list = zacetek;
    int *values = calloc(k, sizeof(int));
    int i = 0;

    bool valid = false;
    int sum = 0;

    while(list != NULL && list->naslednje != NULL) {

        int index = i % k;
        if(i >= k-1) valid = true;
        sum += list->podatek;

        if(valid) sum -= values[index];

        values[index] = list->podatek;

        if(sum == list->naslednje->podatek && valid) {
            Vozlisce* to_delete = list->naslednje;
            list->naslednje = to_delete->naslednje;
            free(to_delete);
        } else {
            list = list->naslednje;
            i++;
        }
    }
}

#ifndef test

int main() {

    return 0;
}

#endif