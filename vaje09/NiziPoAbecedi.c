#include<stdio.h>
#include<stdlib.h>

void iterate(int n,char c1, char c2, int ix, char* niz) {
    if (ix == n) {
        //printf("%s", niz);
        return;
    }

    for(char znak = c1; znak <= c2; znak++) {
        niz[ix] = znak;
        niz[ix + 1] = '\0';
        printf("%s\n", niz);
        iterate(n, c1, c2, ix + 1, niz);

    }
    
}

void izpisi(int n, char zac, char kon) {
    
    char* niz = malloc((n + 1) * sizeof(char));
    iterate(n, zac, kon, 0, niz);
    free(niz);
}

int main() {
    int n;
    char c1, c2;
    scanf("%d %c %c",&n, &c1, &c2);
    izpisi(n, c1, c2);

    return 0;
}