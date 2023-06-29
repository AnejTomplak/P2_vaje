#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int *array(int n) {
    int *t = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", t + i);
    }
    return t;
}
int vsota(int *t, int n) {
    int vsota = 0;
    for(int i = 0; i < n; i++) {
        vsota += t[i];
    }
    return vsota;
}
void izpisi(int *t, bool *valid, int n) {
    printf("{");
    bool prvi = true;
    for(int i = 0; i < n; i++){
        if(valid[i]) {
            if(!prvi){
                printf(", ");
            }
            printf("%d", t[i]);
            prvi = false;
        }
    }
    printf("}\n");
}

void iterate(int n, int *set, int rabimoSe, int ix, bool *used) {
    if(ix == 0) {
        used[0] = true;
        iterate(n, set, rabimoSe - set[0], ix + 1, used);
        return;
    }
    if(rabimoSe == 0) {
        izpisi(set, used, n);
    }
    if(rabimoSe < 0)
        return;
    
    for(int i = 0; i < n; i++) {
        used[i] = true;
        iterate(n, set, rabimoSe - set[i], ix + 1, used);
        used[i] = false;
    }
    /*
    used[ix] = true;
    iterate(n, set, rabimoSe - set[ix], ix + 1, used);
    used[ix] = false;
    iterate(n, set, rabimoSe, ix + 1, used);
    */
}

void izpisiRazbitje(int *set, int n) {
    bool *pripadnost = calloc(n, sizeof(bool));
    int vsotaPodmnozic = vsota(set, n);
    
    iterate(n, set, vsotaPodmnozic / 2, 0, pripadnost);
    free(pripadnost);

}

int main() {
    int n;
    scanf("%d", &n);
    int *set = scan_to_array(n);
    izpisiRazbitje(set, n);
    free(set);

    return 0;
}