#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/** 
 * Vrne indeks minimuma brez upoštevanja elementa -1.
*/

int indeksMinimuma(int* t, int n) {
    
    int iMin = -1;
    for (int i = 0; i < n; i++){
        if(t[i] >= 0 && (iMin < 0 || t[i] < t[iMin])) {
            iMin = i;
        }
    }

    return iMin;
}

void mergeSort(FILE** vhodi, int n, FILE* izhod) {

    // 1 - stevilo vhodnih datotek (trakov), pri katerih smo ze prispeli do konca
    int stKoncanih = 0;

    // 2 - blok[i]: trenutni element iz i-te vhodne datoteke (traku),
    //              oz. -1, če smo pri tej datoteki že prispeli do konca
    int* blok = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        if (fscanf(vhodi[i], "%d", &blok[i]) < 1) {
            blok[i] = -1;
            stKoncanih++;
        }  
    }
    
    while(stKoncanih < n) {
    
    int iMin = indeksMinimuma(blok, n);
    fprintf(izhod, "%d\n", blok[iMin]);

    if (fscanf(vhodi[iMin], "%d", &blok[iMin]) < 1) {
            blok[iMin] = -1;
            stKoncanih++;
        }      
    }

    free(blok);
}

/**
 * Odpre datoteke in vrne tabelo kazalcev na odprte datoteke.
*/
// v stringu mode imamo shranjeno, ali odpremo datoteko za branje ali pisanje
FILE** openFiles(int n, char* mode) {

    char* filename = (char*) malloc(101 * sizeof(char));
    FILE** files = (FILE**) malloc(n * sizeof(FILE*));
    for (int i = 0; i < n; i++) {
        scanf("%s", filename);
        // mode: r, w, a, r+, w+, ... za pisanje, branje, dodajanje ...
        files[i] = fopen(filename, mode);
        // if (files[i] == NULL) {
        //     printf("[Napaka]: %s.\n, fileName);
        // }
    }
    free(filename);
    return files;
}

void closeFiles(FILE** files, int n) {
    for (int i = 0; i < n; i++) {
        fclose(files[i]);
    }
    free(files);
}

int main() {

    int stDatotek = 0;
    scanf("%d", &stDatotek);

    // 1 - odpremo vse datoteke
    FILE** vhodi = openFiles(stDatotek, "r");
    FILE** izhodi = openFiles(1, "w");

    // 2 - zlij datoteke v eno samo
    mergeSort(vhodi, stDatotek, *izhodi);

    // 3 - zapremo vse datoteke
    closeFiles(vhodi, stDatotek);
    closeFiles(izhodi, 1);

    return 0;
}
