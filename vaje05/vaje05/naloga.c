
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int vsota = 0;
    int *i = zac;
    while(i <= kon) {
        vsota += *i;
        i++;
    }
    return vsota;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if(*indeks == -1) {
        *indeks = *kazalec - t;
    }
    else {
        *kazalec = *indeks + t;
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    char *p = niz;
    int* novNiz = (int*) calloc (26, sizeof(int));

    while(*p != '\0') {
        if((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
            int indeks = (*p >= 'a') ? (*p - 'a') : (*p - 'A');
            novNiz[indeks]++; 
        }
         p++;
    }
    *frekvence = novNiz;
    //return frekvence;
}

#ifndef test

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", vsota(&a, &b));

    return 0;
}

#endif
