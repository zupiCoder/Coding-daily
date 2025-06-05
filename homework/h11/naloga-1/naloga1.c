#include <stdlib.h>
#include <stdio.h>
#include "naloga1.h"

Vozlisce *zdesetkaj(Vozlisce *zacetek, int k) {
    Vozlisce *list = NULL; Vozlisce *start = NULL;
    Vozlisce *temp = zacetek;
    int counter = k;

    while(temp != NULL) {
        counter--;
        if(counter == 0) {
            if(list == NULL) {
                start = temp;
                list = start;
            } else {
                list->naslednje = temp;
                list = list->naslednje;
            }
            temp = temp->naslednje;
            
            counter = k;
            continue;
        }
        Vozlisce *erase = temp;
        temp = temp->naslednje;
        free(erase);
    }
    list->naslednje = NULL;

    return start;
}