#include <stdio.h>
#include <stdlib.h>
#include "naloga2.h"

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* create_list(int arr[], int length){
    Vozlisce* start = (Vozlisce*) malloc(sizeof(Vozlisce));
    start->podatek = arr[0];

    Vozlisce* list = start;

    for(int i = 1; i < length; i++) {
        Vozlisce* new = (Vozlisce*) malloc(sizeof(Vozlisce));
        new->podatek = arr[i];
        list->naslednje = new;
        list = list->naslednje;            
    }
    list->naslednje = NULL;
    
    return start;
}

void print_list(Vozlisce* list) {

    printf("[%d]", list->podatek);
    list = list->naslednje;

    while(list != NULL) {
        printf("->[%d]",list->podatek);
        list = list->naslednje;
    }
    printf("\n");
}

void obdelaj_first(Vozlisce* zacetek) {

    Vozlisce* list = zacetek;
    Vozlisce* temp = zacetek->naslednje;

    if(temp == NULL) return;

    int val = list->podatek;

    while(temp->naslednje != NULL) {
        if(val == temp->podatek) {
            list->podatek += temp->podatek;
            Vozlisce* del = temp;
            temp = temp->naslednje;
            list->naslednje = temp;
            free(del);
        } else {
            list->naslednje = temp;
            list = list->naslednje;
            temp = temp->naslednje;
            val = list->podatek;
        }
    }

    if(val == temp->podatek) {
        list->podatek += temp->podatek;
        list->naslednje = NULL;
        free(temp);
    }
}

void obdelaj(Vozlisce* zacetek) {

    Vozlisce* list = zacetek;
    int value = list->podatek;

    while(list != NULL && list->naslednje != NULL) {
        if(value == list->naslednje->podatek) {
            list->podatek += value;
            Vozlisce* to_del = list->naslednje;
            list->naslednje = to_del->naslednje;
            free(to_del);
        } else {
            list = list->naslednje;
            value = list->podatek;
        }
    }
}

#ifndef test
int main() {

    return 0;
}
#endif