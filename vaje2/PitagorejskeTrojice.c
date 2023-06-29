#include<stdio.h>
#include<math.h>

int main() {
    int spMeja, zgMeja;
    scanf("%d%d", &spMeja, &zgMeja);
    int stevec = 0;

    for(int c = spMeja; c <= zgMeja; c++) {
        for(int a = 1; a < c; a++) {
           for(int b = 1; b < c; b++) {
                if(a * a + b * b == c * c)
                    stevec++;
            }
        }
    }
    printf("%d\n", stevec / 2);
    return 0;
}