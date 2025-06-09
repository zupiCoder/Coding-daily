#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* n;
} Vozlisce;

Vozlisce* sticisce(Vozlisce* a, Vozlisce* b) {

    int len_a = 0;
    Vozlisce* temp = a;
    while(temp != NULL) {
        temp = temp->n;
        len_a++;
    }

    int len_b = 0;
    temp = b;
    while(temp != NULL) {
        temp = temp->n;
        len_b++;
    }

    int diff = len_a - len_b;

    if(diff > 0) {
        while(diff != 0) {
            a = a->n;
            diff--;
        }
    } else if(diff < 0) {
        while(diff != 0) {
            b = b->n;
            diff++;
        }
    }

    while(a != NULL && b != NULL) {
        if(a == b) return a;
        
        a = a->n;
        b = b->n;
    }
    return NULL;
}

int main() {


    return 0;
}