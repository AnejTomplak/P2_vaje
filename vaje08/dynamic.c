#include <stdio.h>
#include <stdlib.h>


void printt(int *t, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(", ");
        printf("%3d", t[i]);
    }
    printf("]\n");
}

void printt2d(int **t, int h, int w) {
    printf("[\n");
    for (int i = 0; i < h; i++) {
        printf("  ");
        printt(t[i], w);
    }
    printf("]\n");
}

int *scan_to_array(int n) {
    int *t = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", t + i);
    return t;
}

int **create_table(int height, int width) {
    int **t = (int **) malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
        t[i] = (int *) calloc(width, sizeof(int));
    return t;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dynamic(int items, int *volumes, int *prices, int vBackpack) {
    int **solution = create_table(items + 1, vBackpack + 1);

    // 1 - brez dodanih elementov imamo ceno <0>
    for (int j = 0; j <= vBackpack; j++)
        solution[0][j] = 0;

    // 2 - dodajaj posamezne elemente in izracunaj ceno za vsak volumen
    for (int i = 1; i <= items; i++) {
        int cena = prices[i - 1];
        int prostornina = volumes[i - 1];
        for (int v = 0; v <= vBackpack; v++) {
            if (prostornina > v)
                solution[i][v] = solution[i - 1][v];
            else
                solution[i][v] = max(solution[i - 1][v], 
                                    solution[i - 1][v - prostornina] + cena);
        }
    }

    // 3 - vrni resitev in brisi tabelo z delnimi resitvami
    int najCena = solution[items][vBackpack];

    // printt2d(solution, items + 1, vBackpack + 1);

    for (int i = 0; i < items; i++)
        free(solution[i]);
    free(solution);

    return najCena;
}


int main() {
    int vBackpack, stPredmetov;
    scanf("%d %d", &vBackpack, &stPredmetov);

    int *volumes = (int *) scan_to_array(stPredmetov);
    int *prices = (int *) scan_to_array(stPredmetov);

    int najCena = dynamic(stPredmetov, volumes, prices, vBackpack); 
    printf("%d\n", najCena);

    free(volumes);
    free(prices);

    return 0;
}

