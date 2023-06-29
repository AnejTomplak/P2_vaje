#include <stdio.h>
#include <stdlib.h>

long rekurzija(int n, int k);
long mRekurzija(int n, int k, long **memoizacija);
void disposeTable(long **table);

int main()
{
    int n = 7, k = 5;
    scanf("%d %d", &n, &k);
    

    printf("%ld\n",rekurzija(n, k));
    return 0;
}

long mRekurzija(int n, int k, long **memoizacija)
{
    // printf("%d %d\n",n, k);
    if(memoizacija[n][k] == 0)
    {
        // printf("0");
        long sum = 0;
        if (k - 1 > 0)
            sum += mRekurzija(n, k - 1, memoizacija);
                    
        if(n - k > 0)
            sum += mRekurzija(n - k, k, memoizacija);
        
        if(n - k == 0)
            memoizacija[n][k] = 1 + sum;
        else
            memoizacija[n][k] = sum;
    }
    return memoizacija[n][k];

}
long rekurzija(int n, int k)
{
    long **memoizacija = (long **)malloc((n+2) * sizeof(long *)); // + 2 , zato da je dost placa
    for (int i = 0; i < n+2; i++)
    {
        memoizacija[i] = (long *)calloc((k+1), sizeof(long)); // 2-d tabela
    }
    memoizacija[n+1] = NULL; // zadnji clen je NULL

    long r = mRekurzija(n, k, memoizacija);

    disposeTable(memoizacija);
    return r;
}

void disposeTable(long **table)
{
    long **temp = table;
    while (*temp)
    {
        free(*temp);
        temp++;
    }
    free(table);
}
 
