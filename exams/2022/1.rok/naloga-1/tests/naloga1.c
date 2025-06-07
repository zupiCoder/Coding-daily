#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

int sestEj(char* niz) {

    bool readE = false;
    bool readDig = false;
    int counter = 0;
    int sum = 0;

    char number[4];

    for(int i = 0; i < strlen(niz); i++) {
        char curr = niz[i];

        if(curr == 'E') {
            number[0] = '\0';
            counter = 0;
            readE = true;
        } else if(readE && curr >= '1' && curr <= '9') {
            readDig = true;
            readE = false;
            number[counter++] = curr;
        } else if(readDig && curr >= '0' && curr <= '9') {
            if(counter == 3) {
                readDig = false;
                continue;
            }
            number[counter++] = curr;
        } else if(readDig && curr == '_' && counter == 3) {
            number[3] = '\0';

            sum += atoi(number);
            readDig = false;
        } else {
            readDig = false;
            readE = false;
        }
    }
    return sum;
}

#ifndef test
int main() {


    return 0;
}
#endif