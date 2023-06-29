#include<stdio.h>

int main () {
    int spMeja, zgMeja;
    scanf("%d%d", &spMeja, &zgMeja);
    int odgovor;

    do {
        int poskus = (spMeja + zgMeja) / 2;
        //printf("%d\n", poskus);
        scanf("%d", &odgovor);

        if(odgovor == 1)
            spMeja = poskus + 1;
        if(odgovor == -1)
            zgMeja = poskus - 1;

    } while(odgovor != 0 && spMeja <= zgMeja);

    if (spMeja == zgMeja)
        printf("%d\n", spMeja);
    else if(spMeja < zgMeja)
        printf("%d %d\n", spMeja, zgMeja);
    else
        printf("%s\n", "PROTISLOVJE");
    return 0;
}