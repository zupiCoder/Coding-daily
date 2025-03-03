
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    int l = strlen(niz); int counter = 0;
    
    for(int i = 0; i < l; i++) if(niz[i] == znak) counter++;

    return counter;
}

char* kopirajDoZnaka(char* niz, char znak) {
    char* temp = (char*) malloc((strlen(niz) + 1) * sizeof(char));
    int d = 0;

    for(int i = 0; niz[i] != znak && i < strlen(niz); i++) {
        temp[i] = niz[i];
        d++;
    }
    temp[d] = '\0';

    return temp;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    *stOdsekov = steviloZnakov(niz, locilo) + 1;

    char** t = (char **) malloc(*(stOdsekov) * sizeof(char*));    
    char* temp = niz;

    for(int i = 0; i < *stOdsekov; i++) {
        t[i] = malloc(strlen(niz) * sizeof(char));
        t[i] = kopirajDoZnaka(temp, locilo);
        temp += strlen(t[i]) + 1;
    }

    return t;
}

#ifndef test

int main() {

    return 0;
}

#endif
