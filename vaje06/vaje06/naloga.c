
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    char* p = niz;
    int stevec = 0;
    while(*p != '\0') {
        if(*p == znak)
            stevec++;
        p++;
    }
    return stevec;
}

char* kopirajDoZnaka(char* niz, char znak) {
    char* d = niz;
    int dolzina = strlen(niz);
    char *pNiz = strchr(niz, znak);
    int dNovNiz = (pNiz == NULL) ? (dolzina) : (pNiz - niz);
    int i = 0;

    char* novNiz = (char*) calloc(dNovNiz, sizeof(char));
    

    while((*d != znak) && (*d != '\0')) {
        novNiz[i] = *d;
        d++;
        i++;
    } 
    novNiz[i] = '\0';
    return novNiz;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    char* p = niz;
    int stZetonov = steviloZnakov(niz, locilo) + 1;

    char** tokens = (char**) malloc(stZetonov * sizeof(char));

    for(int i = 0; i < stZetonov; i++) {
        tokens[i] = kopirajDoZnaka(p, locilo);
        p += strlen(tokens[i]) + 1;
    }
    *stOdsekov = stZetonov;

    return tokens;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
