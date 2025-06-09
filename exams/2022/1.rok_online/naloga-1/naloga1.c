#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tests/naloga1.h"

void vstaviPredpono(char* predpona, Oseba** osebe, int stOseb) {
    int len = strlen(predpona);

    for(int i = 0; i < stOseb; i++) {
        Oseba* curr = osebe[i];

        memmove(curr->telefon + len, curr->telefon, strlen(curr->telefon) + 1);
        memcpy(curr->telefon, predpona, len);
    }
}

#ifndef test

int main() {
    return 0;
}

#endif