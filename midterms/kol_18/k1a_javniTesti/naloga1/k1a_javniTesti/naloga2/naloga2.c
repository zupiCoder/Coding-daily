#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "naloga2.h"

int steviloInKta(char* niz, int k, int* indeks) {
    int temp = 0; bool found = false;
    for(int i = 0; i < strlen(niz); i++) {
        if('A' <= niz[i] && niz[i] <= 'Z') temp++;
        if(temp == k && !found) {
            *indeks = i;
            found = true;
        }
    }
    if(temp < k) *indeks = -1; 

    return  temp;
}

void indeksi(char* niz, int** t) {
    int indx = -1;
    int st = steviloInKta(niz, 0, &indx);

    int* arr = malloc((st+1) * sizeof(int));

    int i = 0;
    for(int k = st; k > 0; k--) {
        int temp = -1; 
        steviloInKta(niz, k, &temp);
        arr[i] = temp;
        i++;
    }
    arr[st] = -1;
    *t = arr;
}

char** zadnje(char** nizi) {
    char** temp = nizi;
    int d = 0;
    while(*temp != NULL) {
        d++; temp++;
    }
    char** t = malloc(d * sizeof(char*));

    for(int i = 0; i < d; i++) {
        int indx = -1;
        int st = steviloInKta(nizi[i], 0, &indx);
        int* p = malloc(st * sizeof(int));

        indeksi(nizi[i], &p);
        if(p[0] == -1) {
            t[i] = NULL;
        } else {
            t[i] = &nizi[i][p[0]];        
        }
    }
    return t;
}

int main() {

    return 0;
}
