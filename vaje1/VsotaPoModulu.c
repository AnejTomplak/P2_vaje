#include<stdio.h>

int main() {
    int st1 = getchar() - '0';
    getchar();
    int st2 = getchar() - '0';

    int ostanek = (st1 + st2) % 10;

    putchar('0' + ostanek);
    putchar('\n');
    return 0;
}