#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tests/javni/naloga2.h"
#define MAX_NODES 1000

void izlociDuplikate(Vozlisce* zacetek) {
    Vozlisce** nodes = (Vozlisce**) calloc(MAX_NODES, sizeof(Vozlisce*));

    Vozlisce* temp = zacetek;
    int numOfNodes = 0;

    while(temp != NULL) {
        nodes[numOfNodes++] = temp;
        temp = temp->naslednje;
    }

    for(int i = 0; i < numOfNodes; i++) {
        Vozlisce* curr = nodes[i];

        if(curr == NULL) continue;

        for(int j = (i+1); j < numOfNodes; j++) {
            Vozlisce* next = nodes[j];

            if(next == NULL) continue;

            if(curr->p == next->p) {
                free(next);
                nodes[j] = NULL;
            }
        }
    }

    Vozlisce* curr = NULL;
    for(int i = 0; i < numOfNodes; i++) {
        if(nodes[i] == NULL) continue;
        curr = nodes[i];

        for(int j = (i+1); j < numOfNodes; j++) {
            Vozlisce* next = nodes[j];

            if(next != NULL) {
                curr->naslednje = next;
                break;
            }
        }
    }
    curr->naslednje = NULL;
}

#ifndef test
int main() {

    return 0;
}
#endif