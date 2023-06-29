#include <stdio.h>
#include <stdlib.h>

void rekurzija(char c, int n, int k);
void mRekurzija(int n, int k, long ***memoizacija, long *zapis, int l);
void brezMemo(int n, int k, long *zapis, int l);
void disposeTable(long ***table);
void izpisTabele(long *zapis, int l);

int main()
{
    int n = 400, k = 400;
    scanf("%d %d", &n, &k);

    // printf("m\n");
    rekurzija('m', n, k);
    return 0;
}

void mRekurzija(int n, int k, long ***memoizacija, long *zapis, int l)
{
    if(memoizacija[n][k][0] == 0)
    {
        if(n - k > 0)
        {
            zapis[l] = k;
            memoizacija[n][k] = zapis;
            mRekurzija(n-k, k, memoizacija, memoizacija[n][k], l+1);
        }
        if(n - k == 0)
        {
            zapis[l] = k;
            memoizacija[n][k] = zapis;
            izpisTabele(zapis, l);
        }
        if (k - 1 > 0)
        {
            memoizacija[n][k] = zapis;
            mRekurzija(n, k-1, memoizacija, memoizacija[n][k], l);
        }   
    }
}

void rekurzija(char c, int n, int k)
{
    // printf("r: %c %d %d\n",c, n, k);
    int x = n + 2;
    int y = k + 2;
    int z = n + 1;
    long *zapis = malloc(z * sizeof(long));

    long ***memoizacija = (long ***)malloc(x * sizeof(long **));

    // printf("2\n");
    for (int i = 0; i < x; i++)
    {
    // printf("3\n");
        memoizacija[i] = (long **)malloc(y * sizeof(long **));
        for (int j = 0; j < y; j++)
        {
    // printf("4\n");
            memoizacija[i][j] = (long *) calloc(z, sizeof(long));
        }
        memoizacija[i][k+1] = NULL; 
    }
    memoizacija[n+1] = NULL;

    // printf("5\n");
    if(c == 'm')
        mRekurzija(n, k, memoizacija, zapis, 1);
    else
        brezMemo(n, k, zapis, 0);

    // disposeTable(memoizacija);
}

void disposeTable(long ***table)
{
    for (long ***pi = table; pi; pi++)
    {
        for (long **pj = *pi; pj; pj++)
            free(*pj);
        free(*pi);
    }
    free(table);
}

void izpisTabele(long *t, int l)
{
    for (int i = 1; i <= l; i++)
    {
        printf("%ld",t[i]);
        if(i < l)
            printf(" + ");
        else
            printf("\n");
    }
}
void brezMemo(int n, int k, long *zapis, int l)
{
    
    if(n - k == 0)
    {
        zapis[l] = k;
        izpisTabele(zapis, l);
    }
                
    if(n - k > 0)
    {
        zapis[l] = k;
        brezMemo(n-k, k, zapis, l+1);
    }

    if (k - 1 > 0)
    {
        brezMemo(n, k-1, zapis, l);
    }

}
