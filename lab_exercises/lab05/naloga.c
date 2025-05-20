#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naloga.h"
#define SIZE 26

int vsota(int* zac, int* kon) {
    int sum = 0;
    int* temp = zac;

    while(temp <= kon) {
        sum += *temp;
        temp++;
    }
    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {

    if(*indeks == -1) {
        int* temp = t; int indx = 0;
        while(temp != *kazalec) {
            temp++; indx++;
        }

        *indeks = indx;
    } else {
        int *p = &t[*indeks];
        *kazalec = p;
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    int *t = (int*) calloc(SIZE, sizeof(int));
    
    for (int i = 0; niz[i] != '\0'; i++) {
        char temp = niz[i];
        int indx = -1;

        if(temp >= 'a' && temp <= 'z') {
            indx = (temp - 'a');
        } else if(temp >= 'A' &&  temp <= 'Z') {
            indx = (temp - 'A');
        } else continue;

        t[indx]++;
    }
    
    *frekvence = t;
}

#ifndef test

int main() {

    return 0;
}

#endif