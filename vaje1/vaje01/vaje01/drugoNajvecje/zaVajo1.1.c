#include<stdio.h>
#include<stdbool.h>


int main() {
    int drugoNaj;
    int stevec = getchar() - '0';
    getchar();
    int naj = getchar() - '0';
    getchar();
    for(int i = 0; i < stevec - 1; i++) {
        int st = getchar() - '0';
        getchar();
        if(st >= naj) {
            drugoNaj = naj;
            naj = st;
        }
    }
    putchar('0' + drugoNaj);
    putchar('\n');

    return 0;
}