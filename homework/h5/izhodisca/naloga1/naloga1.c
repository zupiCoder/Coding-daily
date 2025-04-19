/*
Prevajanje in poganjanje skupaj z datoteko test01.c:
gcc -D=test test01.c naloga1.c
./a.out
*/
#include <stdio.h>
#include <stdlib.h>
#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    int *l = t; int *r = t;

    while(*(l-1) != 0) l--;
    while(*(r+1) != 0) r++;

    *dolzina = (r - l) + 1;
    *konec = r;

    return l;
}

#ifndef test
int main() {
    return 0;
}
#endif
