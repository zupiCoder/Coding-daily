
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -Dtest testXY.c naloga1.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

void nastavi(Vozlisce* zacetek) {
    Vozlisce* list = zacetek;

    while(list->naslednje != NULL) {
        Vozlisce* next = list->naslednje;
        list->nn = next->naslednje;

        list = list->naslednje;
    }
    list->nn = NULL;
}

#ifndef test

int main() {

    return 0;
}

#endif
