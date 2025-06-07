#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dvonivojskaKonstrukcija.h"

Zunanje* izdelajDvonivojsko(int* t, int n) {
    Zunanje* construction = NULL;
    Zunanje* list = construction;

    Zunanje* previous = list;

    bool got_start = false;

    for(int i = 0; i < n; i++) {
        list = construction;
        int el = t[i];

        while(list != NULL) {
            Notranje* node = list->zadnje;
            if(el >= node->podatek) {
                Notranje* new_node = (Notranje*) malloc(sizeof(Notranje));
                node->desno = new_node;
                new_node->podatek = el;
                new_node->desno = NULL;
                list->zadnje = new_node;
                break;
            } else {
                previous = list;
                list = list->dol;
            }
        }
        
        if(list == NULL) {
            list = (Zunanje*) malloc(sizeof(Zunanje));
            Notranje* new_node = (Notranje*) malloc(sizeof(Notranje));
            new_node->podatek = el;
            new_node->desno = NULL;

            list->prvo = new_node;
            list->zadnje = new_node;
            list->dol = NULL;

            if(!got_start) {
                construction = list;
                got_start = true;
            }

            if(previous != NULL) previous->dol = list;
        }
    }
    return construction;
}

#ifndef test
int main() {
    return 0;
}
#endif