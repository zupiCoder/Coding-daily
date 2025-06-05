#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tests/javni/naloga3.h"

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    Vozlisce* list = start;
    int index = 0;

    while(list->desno != NULL) {
        list = list->desno;
        index++;
    }

    list = start;
    
    Vozlisce* new = (Vozlisce*) malloc(sizeof(Vozlisce));
    Vozlisce* diagonal = new;

    while(list != NULL && new != NULL) {
        if(index == 0) {
            new->desno = NULL;
            new->dol = NULL;
        }

        Vozlisce* curr = list;
        int counter = 0;
        while(counter != index) {
            counter++;
            curr = curr->desno;
        }
        new->vsebina = curr->vsebina;

        *vsota += new->vsebina;
        new->dol = NULL;
        if(list->dol == NULL || index == 0) {
            new->desno = NULL;
        }else {
            new->desno = (Vozlisce*) malloc(sizeof(Vozlisce));
        }
        index--;
        list = list->dol;
        new = new->desno;
    }
    return diagonal;
}

#ifndef test

int main() {
    // "Ce "zelite funkcijo <diagonala> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
