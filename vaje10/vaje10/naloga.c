
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for(int i = 0; i < stStudentov; i++) {
        if(studentje[i]->vpisna == vpisna) {
            return i;
        }
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    for(int i = 0; i < student->stPO; i++) {
        if(strcmp(student->po[i].predmet, predmet) == 0) { //v c-ju moramo za comparanje stringov uporabiti strcmp !!
            return i; //strcmp vrne 0, ce sta stringa enaka !!!
        }
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int student = poisciStudenta(studentje, stStudentov, vpisna);

    if(student != -1) {

        int ix = poisciPO(studentje[student], predmet);
        if(ix != -1) {
            studentje[student]->po[ix].ocena = ocena;
        }
        else {
            int stPO = studentje[student]->stPO;
            strcpy(studentje[student]->po[stPO].predmet, predmet);
            studentje[student]->po[stPO].ocena = ocena;
            studentje[student]->stPO++;
        }
    }
    else {
        Student* novStudent = malloc(sizeof(Student));
        novStudent->vpisna = vpisna;
        novStudent->stPO = 0;
        novStudent->po = malloc(10 * sizeof(PO));

        strcpy(novStudent->po[0].predmet, predmet);
        novStudent->po[0].ocena = ocena;

        *studentje = realloc(*studentje, (stStudentov + 2) * sizeof(Student*));
        studentje[stStudentov] = novStudent;
        studentje[stStudentov + 1] = NULL;
        stStudentov++;

        free(novStudent);
    }

    return stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
