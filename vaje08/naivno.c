#include <stdio.h>
#include <stdlib.h>

int *scan_to_array(int n) {
    int *t = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", t + i);
    return t;
}

int optimalna_cena(int stPredmetov, int *prostornine, int *cene, int vNah) {
    int najCena = 0;
    int stMnozic = 1 << stPredmetov;

    for (int m = 0; m < stMnozic; m++) {
        int mnozica = m;
        int i = 0;
        int cena = 0;
        int prostornina = 0;
        while (mnozica > 0) {
            if (mnozica % 2 == 1) {
                cena += cene[i];
                prostornina += prostornine[i];
            }
            i++;
            mnozica /= 2;
        }
        if (prostornina <= vNah && cena > najCena) {
            najCena = cena;
        }
    }
    return najCena;
}


int main() {
    int vBackpack, stPredmetov;
    scanf("%d %d", &vBackpack, &stPredmetov);

    int *volumes = (int *) scan_to_array(stPredmetov);
    int *prices = (int *) scan_to_array(stPredmetov);

    int najCena = optimalna_cena(stPredmetov, volumes, prices, vBackpack);
    printf("%d\n", najCena);

    free(volumes);
    free(prices);

    return 0;
}

