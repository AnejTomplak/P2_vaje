#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool smo_ze[1001][11][1001];
int prihranek = 0;


int *scan_to_array(int n) 
{
    int *t = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    return t;
}

int ***create_table(int height, int width, int depth)
{
    int ***t = (int ***) malloc(height * sizeof(int **));
    for (int i = 0; i < height; i++)
    {
        t[i] = (int **) malloc(width * sizeof(int *));
        for (int j = 0; j < width; j++)
            t[i][j] = (int *) calloc(depth, sizeof(int));
    }
    return t;
}

void delete_table(int ***t, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            free(t[i][j]);
        free(t[i]);
    }
    free(t);
}

/**
 * Vrne ceno optimalnega nahrbtnika
 *
 * @n stevilo vseh predmetov
 * @volumes prostornine vseh predmetov
 * @prices cene vseh predmetov
 * @ix indeks trenutno obravnavanega predmeta
 * @vBackpack preostala prostornina v nahrbtniku
 * @memo tabela za pomnjenje ze izracunanih vrednosti
 */

int search(int n, int *volumes, int *prices, int ix, int preostaloStLihih, int vBackpack, int ***memo)
{
    // 1 - ni vec predmetov -> ne doprinesemo nic vec k ceni
    if (ix == n)
        return 0;

    // **
    if (smo_ze[ix][preostaloStLihih][vBackpack] && memo[ix][preostaloStLihih][vBackpack] == 0)
        prihranek++;
    // **

    if (smo_ze[ix][preostaloStLihih][vBackpack])
    // if (memo[ix][preostaloStLihih][vBackpack] > 0)
        // resitev za prvih <ix> elementov in volumen <v> zracunali ze prej
        return memo[ix][preostaloStLihih][vBackpack];

    int cena_brez = search(n, volumes, prices, ix + 1, preostaloStLihih, vBackpack, memo);
    memo[ix][preostaloStLihih][vBackpack] = cena_brez;
    if (volumes[ix] <= vBackpack && (preostaloStLihih - (volumes[ix] % 2) >= 0)) {
        // imamo prostor za predmet[ix] 
        int cena_z = prices[ix] + search(n, volumes, prices, ix + 1, 
                                    preostaloStLihih - (volumes[ix] % 2), vBackpack - volumes[ix], memo);

        if (cena_z > cena_brez)
            memo[ix][preostaloStLihih][vBackpack] = cena_z;
    }
    smo_ze[ix][preostaloStLihih][vBackpack] = true;
    return memo[ix][preostaloStLihih][vBackpack];
}

int maximize_backpack(int n, int *volumes, int*prices, int stLihih, int vBackpack)
{
    // memo[i, j, k] -> naj cena pri vkljucitvi prvih <i> predmetov, kjer je kvecjemu 
    //                  <j> lihih brez, da bi presegli volumen <j>
    int ***memo = create_table(n + 1, stLihih + 1, vBackpack + 1);
    int maxPrice = search(n, volumes, prices, 0, stLihih, vBackpack, memo);
    delete_table(memo, n + 1, stLihih + 1);
    return maxPrice;
}

int main()
{
    int vBackpack, stPredmetov, stLihih;
    scanf("%d %d %d", &vBackpack, &stPredmetov, &stLihih);

    int *volumes = scan_to_array(stPredmetov);
    int *prices = scan_to_array(stPredmetov);

    int maxPrice = maximize_backpack(stPredmetov, volumes, prices, stLihih, vBackpack);
    printf("%d\n", maxPrice);

    // printf("prihranek: %d\n", prihranek);

    free(volumes);
    free(prices);

    return 0;
}