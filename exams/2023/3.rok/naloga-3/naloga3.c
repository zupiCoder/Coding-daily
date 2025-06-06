#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int najdi_znak(char niz[], int len) {
    char max = 0;
    int index = 0;

    for(int i = 0; i < strlen(niz) && i < len; i++) {
        if(niz[i] > max) {
            max = niz[i];
            index = i;
        }
    }
    return index;
}

void izpisi(char niz[], char temp[], int index) {
    
    if(strlen(temp) == 0) return;

     if(strlen(temp) == 1) {
        for(int i = 0; i < index; i++) printf(" ");
        printf("%c\n", temp[0]);
        return;
    }

    for(int i = 0; i < index; i++) printf(" ");
    for(int i = 0; i < strlen(temp); i++) printf("%c", temp[i]);
    printf("\n");

    int len = strlen(temp);
    int curr_index = najdi_znak(&niz[index], len) + index;

    //1. klic
    for(int i = index; i < curr_index; i++) temp[i - index] = niz[i];
    temp[curr_index - index] = '\0';
    izpisi(niz, temp, index);

    //2.klic, samo znak
    temp[0] = niz[curr_index];
    temp[1] = '\0';
    izpisi(niz, temp, curr_index);

    //3.klic
    for(int i = (curr_index+1); i < (index + len); i++) temp[i - (curr_index + 1)] = niz[i];
    temp[(index+len) -(curr_index + 1)] = '\0';
    izpisi(niz, temp, curr_index+1);
}

int main() {

    char niz[201];
    char temp[201];

    scanf("%s", niz);

    strcpy(temp, niz);

    izpisi(niz, temp, 0);

    return 0;
}