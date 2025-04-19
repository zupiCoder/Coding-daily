/*
Prevajanje in poganjanje skupaj z datoteko test01.c:
gcc -D=test test01.c naloga2.c
./a.out
*/
#include <stdio.h>
#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

void uredi(int** a, int** b, int** c) {
   if(**a > **b) zamenjaj(a,b); //check if a > b => b a c
   if(**b > **c) zamenjaj(b,c); // if b > c => c a b, vemo da b > c in a > b
   if(**a > **b) zamenjaj(a,b);// if a > b => [c b a]
}

#ifndef test
int main() {
    int a = 10;
    int b = 20;
    int *pa = &a;
    int *pb = &b;

    zamenjaj(&pa, &pb);

    printf("%d %d\n", *pa, *pb);

    return 0;
}
#endif
