#include<stdio.h>

int vsotaDeliteljev(int stevilo) {
    int vsota = 0;
    for(int i = 1; i < stevilo; i++) {
        if(stevilo % i == 0)
            vsota += i;
    }
    return vsota;
}

int aliJePrijateljsko(int stevilo) {
    int vsota = vsotaDeliteljev(stevilo);
    if(vsota == stevilo) {
        printf("%s\n", "NIMA");
        return 0;
    }
    int deliteljiVsote = vsotaDeliteljev(vsota);
    if(deliteljiVsote == stevilo)
        printf("%d\n", vsota);
    else 
        printf("%s\n", "NIMA");
    return 0;
}

int main () {
    int stevilo;
    scanf("%d", &stevilo);
    int rez = aliJePrijateljsko(stevilo);
    return 0;
}