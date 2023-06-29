
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    int vsota = 0;
    Vozlisce* temp = zacetek;

    while (temp != NULL) {
        vsota += temp->podatek;
        temp = temp->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL) {
        return 0;
    }
    int vsota = zacetek->podatek;
    vsota += vsotaR(zacetek->naslednje);

    return vsota;
}

Vozlisce *CreateNode(int data, Vozlisce *next) {
    Vozlisce *node = (Vozlisce*) malloc(sizeof(Vozlisce));
    node->podatek = data;
    node->naslednje = next;

    return node;
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    
    // for (Vozlisce* temp = zacetek; temp != NULL; temp->naslednje) {
    // if (element > temp->podatek) {
    

    if (zacetek == NULL || element < zacetek->podatek) {
        return CreateNode(element, zacetek);
    }
    else {
        Vozlisce *temp = zacetek;
        while (temp->naslednje != NULL && temp->naslednje->podatek < element) {
            temp = temp->naslednje;    
        }
        temp->naslednje = CreateNode(element, temp->naslednje);
    }
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
     if (zacetek == NULL || element < zacetek->podatek) {
        return CreateNode(element, zacetek);
    }
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
