#include<stdio.h>

int main() {
    int n = getchar() - '0';
    getchar();
    int najvecje = getchar() - '0';
    int DrugoNajvecje = 0;

    for(int i = 0; i < n - 1; i++) {
        getchar();
        int st = getchar() - '0';
        if(st > najvecje) {
            DrugoNajvecje = najvecje;
            najvecje = st;
        }
        else if(st <= najvecje && st > DrugoNajvecje) {
            DrugoNajvecje = st;
        }
    }
    putchar('0'+DrugoNajvecje);
    putchar('\n');
    return 0;
}