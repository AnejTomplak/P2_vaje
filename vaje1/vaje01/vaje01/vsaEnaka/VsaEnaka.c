#include<stdio.h>

int main() {
    int n = getchar() - '0';
    getchar();

    int enako = 1;
    int prvi = getchar() - '0';

    for(int i = 0; i < n - 1 ; i++) {
        getchar();
        int st = getchar() - '0';
        if(prvi != st) {
            enako = 0;
        }
        prvi = st;
    }
    putchar('0'+enako);
    putchar('\n');
    return 0;
}