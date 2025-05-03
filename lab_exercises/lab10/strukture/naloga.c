#include <stdlib.h>
#include <string.h>
#include "naloga.h"

int poisciStudenta(Student **studentje, int stStudentov, int vpisna) {
    for(int i = 0; i < stStudentov; i++) {
        if(studentje[i]->vpisna == vpisna) return i;
    }
    return -1;
}

int poisciPO(Student *student, char *predmet) {
    for(int i = 0; i < student->stPO; i++) {
        if(strcmp(student->po[i].predmet, predmet) == 0) return i;
    }
    return -1;
}

int dodaj(Student **studentje, int stStudentov, int vpisna, char *predmet, int ocena) {
    int indx = poisciStudenta(studentje, stStudentov, vpisna);

    if(indx == -1) {
        Student* novStudent = (Student*) malloc(sizeof(Student));
        PO* po = (PO*) malloc(10 * sizeof(PO));

        po[0].ocena = ocena;
        strcpy(po[0].predmet, predmet);

        novStudent->vpisna = vpisna;
        novStudent->po = po;
        novStudent->stPO = 1;

        studentje[stStudentov] = novStudent;

        return stStudentov + 1;
    } else {
        Student* s = studentje[indx];

        int indxPO = poisciPO(s, predmet);
        if(indxPO == -1) {
            int stPO = s->stPO;
            s->po[stPO].ocena = ocena;
            strcpy(s->po[stPO].predmet, predmet);
            s->stPO++;
        } else {
            s->po[indxPO].ocena = ocena;
        }
        return stStudentov;
    }
    return -1;
}

#ifndef test

int main() {
    return 0;
}

#endif