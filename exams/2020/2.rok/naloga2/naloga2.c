#include <stdio.h>
#include <stdlib.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v) {

    Vozlisce* temp = zac;
    Vozlisce* p = (Vozlisce*) malloc(sizeof(char));
    p->naslednje = zac;

    if(zac == v) {
        zac = zac->naslednje;
        free(temp);
        return zac;
    }

    while(temp != NULL && temp->naslednje != NULL) {

        if(temp == v) {
            p->naslednje = temp->naslednje;
            temp = temp->naslednje;
            free(v);
        } else {
            temp = temp->naslednje;
        }
        p = p->naslednje;
    }
    return zac;
}

Vozlisce* izloci_(Vozlisce* zac, Vozlisce* v) {
    if (zac == v) {
        Vozlisce* nov_zac = zac->naslednje;
        free(zac);
        return nov_zac;
    }

    Vozlisce* pred = zac;
    while (pred->naslednje != NULL && pred->naslednje != v) {
        pred = pred->naslednje;
    }

    if (pred->naslednje == v) {
        pred->naslednje = v->naslednje;
        free(v);
    }

    return zac;
}

Vozlisce* izlociRekurzivno(Vozlisce* zac, Vozlisce* v) {

    if(zac == NULL) return NULL;

    if(zac == v && zac->naslednje == NULL) {
        free(v);
        return NULL;   
    } else if(zac == v) {
        Vozlisce* temp = zac->naslednje;
        free(v);
        return temp;
    }
    zac->naslednje = izlociRekurzivno(zac->naslednje, v);

    return zac;
}

Vozlisce* novoVozlisce(int podatek) {
    Vozlisce* v = malloc(sizeof(Vozlisce));
    v->podatek = podatek;
    v->naslednje = NULL;
    return v;
}

void izpisiSeznam(Vozlisce* z) {
    while (z != NULL) {
        printf("%d -> ", z->podatek);
        z = z->naslednje;
    }
    printf("NULL\n");
}

int main() {

    Vozlisce* v1 = novoVozlisce(1);
    Vozlisce* v2 = novoVozlisce(2);
    Vozlisce* v3 = novoVozlisce(3);
    Vozlisce* v4 = novoVozlisce(4);
    v1->naslednje = v2;
    v2->naslednje = v3;
    v3->naslednje = v4;

    izpisiSeznam(v1);

    v1 = izlociRekurzivno(v1, v3);
    izpisiSeznam(v1);

    v1 = izlociRekurzivno(v1, v1);
    izpisiSeznam(v1);

    Vozlisce* vx = novoVozlisce(100);
    v1 = izlociRekurzivno(v1, vx);
    izpisiSeznam(v1);
    free(vx);

    while (v1 != NULL) {
        Vozlisce* tmp = v1;
        v1 = v1->naslednje;
        free(tmp);
    }

    return 0;
}