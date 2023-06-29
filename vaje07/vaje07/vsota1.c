#include<stdio.h>
#include<stdlib.h>


int nacini(int n, int k) {
    if(n < 0) {
        return 0;
    }
    if(k == 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    return nacini(n - k, k) + nacini(n, k - 1);
}
 


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", nacini(n, k));
    return 0;
}