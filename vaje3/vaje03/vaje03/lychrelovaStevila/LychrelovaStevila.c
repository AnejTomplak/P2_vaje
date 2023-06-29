#include<stdio.h>
#include<stdbool.h>
#define MEJA 100000000000000000L

long Inverz(long stevilo) {
    long inverz = 0;
    while (stevilo != 0) {
        inverz = inverz * 10;
        inverz = inverz + stevilo % 10;
        stevilo /= 10;
    }
    return inverz;
}

bool jePalindrom(long stevilo) {
    return (stevilo == Inverz(stevilo));
}
bool jeLychrelovo(long stevilo, int maxIteracij) {
    int stKorakov = 0;
    do {
        stevilo = stevilo + Inverz(stevilo);
        stKorakov++;
    } while(stKorakov < maxIteracij && stevilo <= MEJA && !jePalindrom(stevilo));
    return !jePalindrom(stevilo);
}

int main() {
    int maksIteracij, spMeja, zgmeja = 0;
    int stLychrelovih = 0;
    scanf("%d %d %d", &maksIteracij, &spMeja, &zgmeja);

    for(int i = spMeja; i <= zgmeja; i++) {
        if(jeLychrelovo(i, maksIteracij))
            stLychrelovih++;
    }
    printf("%d\n", stLychrelovih);
    return 0;
}