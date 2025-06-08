#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "naloga2.h"

Vozlisce* zlij(Vozlisce* a, Vozlisce* b) {
    Vozlisce* start = NULL;
    Vozlisce* list = NULL;

    if(a->podatek > b->podatek) {
        list = b;
        b = b->naslednje;
    } else {
        list = a;
        a = a->naslednje;
    }
    start = list;

    while(a != NULL && b != NULL) {

        if(a->podatek < b->podatek) {
            list->naslednje = a;
            a = a->naslednje;
        } else {
            list->naslednje = b;
            b = b->naslednje;
        }
        list = list->naslednje;
    }
    while(a != NULL) {
        list->naslednje = a;
        a = a->naslednje;
        list = list->naslednje;
    }

    while(b != NULL) {
        list->naslednje = b;
        b = b->naslednje;
        list = list->naslednje;
    }
    return start;
}

#ifndef test

int main() {
    return 0;
}

#endif