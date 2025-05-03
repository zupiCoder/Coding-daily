#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "naloga.h"

/*
    typedef struct Vozlisce Vozlisce;
    struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče
    Vozlisce* naslednje; // kazalec na naslednje vozlišče ( NULL, če ga ni)
    };
*/

int vsotaI(Vozlisce *zacetek) {
    if(zacetek == NULL) return 0;
                                        
    int sum = 0;

    while(zacetek != NULL) {
        sum += zacetek->podatek;
        zacetek = zacetek->naslednje;
    }
    return sum;
}

int vsotaR(Vozlisce *zacetek) {
    if(zacetek == NULL) return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce *vstaviUrejenoI(Vozlisce *zacetek, int element) {
    Vozlisce *new = (Vozlisce *) malloc(sizeof(Vozlisce));
    Vozlisce *temp = zacetek;

    if(zacetek == NULL) {
        new->naslednje = NULL;
        new->podatek = element;
        return new;
    }

    if(element < temp->podatek) {
        new->naslednje = temp;
        new->podatek = element;
        return new;
    }

    //PAZI order pogojev V && kontrolnih stavkih!!
    //najprej preverimo da ni null, nato element > temp...
    while(temp->naslednje != NULL && element > temp->naslednje->podatek)
        temp = temp->naslednje;

    if(temp->naslednje == NULL) {
        new->podatek = element;
        new->naslednje = NULL;
        temp->naslednje = new;
    } else {
        Vozlisce *t = temp->naslednje;
        temp->naslednje = new;
        new->naslednje = t;
        new->podatek = element;
    }
    return zacetek;
}

Vozlisce *vstaviUrejenoR(Vozlisce *zacetek, int element) {
    if(zacetek == NULL) {
        Vozlisce *new = (Vozlisce *) malloc(sizeof(Vozlisce));
        new->podatek = element;
        new->naslednje = NULL;
        return new;
    }

    if(element <= zacetek->podatek) {
        Vozlisce *new = (Vozlisce *) malloc(sizeof(Vozlisce));
        new->naslednje = zacetek;
        new->podatek = element;
        return new;
    }       
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);

    return zacetek;
}

#ifndef test
int main() {
    return 0;
}
#endif