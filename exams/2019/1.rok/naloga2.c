#include <stdio.h>
#include <stdlib.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
int podatek;
Vozlisce* naslednje;
};

Vozlisce* obrni(Vozlisce* zacetek) {
    Vozlisce* temp = zacetek;

    while(temp->naslednje != NULL) temp = temp->naslednje;

    Vozlisce* newList = temp;

    


    
}

Vozlisce* obrniRecursive(Vozlisce* zacetek) {
    if(zacetek->naslednje == NULL) return zacetek;

    Vozlisce *temp = obrniRecursive(zacetek);
    temp->naslednje = zacetek;

    return temp;
}

int main() {

    Vozlisce* a = malloc(sizeof(Vozlisce));
    Vozlisce* b = malloc(sizeof(Vozlisce));
    Vozlisce* c = malloc(sizeof(Vozlisce));
    Vozlisce* d = malloc(sizeof(Vozlisce));
    Vozlisce* e = malloc(sizeof(Vozlisce));

    a->podatek = 7; a->naslednje = b;
    b->podatek = 2; b->naslednje = c;
    c->podatek = 6; c->naslednje = d;
    d->podatek = 9; d->naslednje = e;
    e->podatek = 3; e->naslednje = NULL;

    Vozlisce* novi = obrniRecursive(a);

    while (novi != NULL) {
        printf("%d ", novi->podatek);
        novi = novi->naslednje;
    }
    printf("\n");

    return 0;
}