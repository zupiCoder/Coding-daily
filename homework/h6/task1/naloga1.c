#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char* zdruzi(char** nizi, char* locilo) {
    int length = 0; int temp = 0;

    for(int i = 0; nizi[i] != NULL; i++) {
        length += strlen(nizi[i]); temp++;
    }
    length += strlen(locilo) * (temp-1);

    char* str = (char*) malloc((length+1) * sizeof(char));

    for(int i = 0; i < temp; i++) {
        if(i > 0) strcat(str, locilo);  
        strcat(str, nizi[i]);
    }
    str[length] = '\0'; 

    return str;
}
#ifndef test

int main() {
    return 0;
}

#endif
