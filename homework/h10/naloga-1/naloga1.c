#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "naloga1.h"

int compare(const void *a, const void *b) {
    VO *va = *(VO **)a;
    VO *vb = *(VO **)b;

    if(va->ocena == vb->ocena) {
        return va->vpisna - vb->vpisna;
    } else {
        return vb->ocena - va->ocena;
    }
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    VO** v = (VO**) malloc(1000 * sizeof(VO*));

    int ix = 0;

    for(int i = 0; i < stStudentov; i++) {
        Student *temp = studentje[i];
        for(int j = 0; j < temp->stPO; j++) {
            if(strcmp(temp->po[j].predmet, predmet) == 0) {
                if(temp->po[j].ocena >= 6) {
                    v[ix] = (VO*) malloc(sizeof(VO));
                    
                    v[ix]->vpisna = temp->vpisna;
                    v[ix]->ocena = temp->po[j].ocena;
                    ix++;
                }
                break;
            }
        }
    }
    *stVO = ix;
    qsort(v, *stVO, sizeof(VO*), compare);

    return v;
}