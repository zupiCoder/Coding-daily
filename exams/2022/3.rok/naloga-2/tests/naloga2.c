#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "naloga2.h"

#define MAX 1002

void vstaviH1(Vozlisce* zacetek) {
    Vozlisce** nodes = (Vozlisce**) malloc(MAX * sizeof(Vozlisce*));
    for(int i = 0; i < MAX; i++) nodes[i] = (Vozlisce*) malloc(sizeof(Vozlisce));

    nodes[0] = NULL;
    Vozlisce* list = zacetek;
    int ind = 1;

    for(int i = 1; list != NULL; i++) {
        nodes[i] = list;
        list = list->naslednje;
        ind++;
    }
    nodes[ind] = NULL;

    char prefix[] = "<h1>";
    char suffix[] = "</h1>";

    for(int ix = 1; ix < ind; ix++) {
        Vozlisce* prev = nodes[ix-1];
        Vozlisce* curr = nodes[ix];
        Vozlisce* next = nodes[ix+1];

        if((prev != NULL && strlen(prev->niz) > 0) || (next != NULL && strlen(next->niz) > 0)) continue;

        if(strlen(curr->niz) == 0) continue;

        memmove(curr->niz + strlen(prefix), curr->niz, strlen(curr->niz) + 1);
        memcpy(curr->niz, prefix, strlen(prefix));
        strcat(curr->niz, suffix);
    }
}

#ifndef test

int main() {
    
    return 0;
}

#endif