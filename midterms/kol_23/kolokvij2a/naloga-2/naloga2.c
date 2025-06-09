#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tests/javni/naloga2.h"

#define MAX_NODES 1001

Vozlisce* returnList(Vozlisce **nodes, int numNodes) {
    bool first = true;
    Vozlisce* list = NULL;

    Vozlisce* curr = NULL;
    for(int i = 0; i < numNodes; i++) {
        if(nodes[i] == NULL) continue;
        curr = nodes[i];
        if(first) {
            list = curr;
            first = false;
        }

        for(int j = i+1; j < numNodes; j++) {
            if(nodes[j] == NULL) continue;
            Vozlisce* next = nodes[j];
            curr->naslednje = next;
            break;
        }
    }
    if(curr != NULL)
        curr->naslednje = NULL;

    return list;
}

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    Vozlisce** nodes_a = (Vozlisce**) calloc(MAX_NODES, sizeof(Vozlisce*));
    Vozlisce** nodes_b = (Vozlisce**) calloc(MAX_NODES, sizeof(Vozlisce*));

    Vozlisce* temp = a;
    int numNodesFirst = 0, numNodesSecond = 0;

    while(temp != NULL) {
        nodes_a[numNodesFirst++] = temp;
        temp = temp->naslednje;
    }

    temp = b;
    while(temp != NULL) {
        nodes_b[numNodesSecond++] = temp;
        temp = temp->naslednje;
    }

    for(int i = 0; i < numNodesFirst; i++) {
        if(nodes_a[i] == NULL) continue;
        Vozlisce* curr_a = nodes_a[i];
        for(int j = 0; j < numNodesSecond; j++) {
            if(nodes_b[j] == NULL) continue;
            Vozlisce* curr_b = nodes_b[j];

            if(curr_a->podatek == curr_b->podatek) {
                nodes_a[i] = NULL;
                nodes_b[j] = NULL;
                free(curr_a);
                free(curr_b);
            }
        }   
    }

    *noviA = returnList(nodes_a, numNodesFirst);
    *noviB = returnList(nodes_b, numNodesSecond);

    free(nodes_a);
    free(nodes_b);
}

#ifndef test

int main() {

    return 0;
}

#endif