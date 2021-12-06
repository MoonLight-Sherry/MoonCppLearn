#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long mat[n][n];
    long long avr[n];
    for (int i = 0; i < n; ++i)
    {
        getchar();
        for (int j = 0; j < n; ++j)
        {
            long long cur;
            scanf("%lld", &cur);
            mat[i][j] = cur;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        long long sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += mat[i][j];
        }
        avr[i] = sum / n;
    }
    for (int j = 0; j < n; ++j)
    {
        int minRow = 0;
        for (int i = 0; i < n; ++i)
        {
            minRow = avr[minRow] < avr[i] ? minRow : i;
        }
        for (int i = 0; i < n; ++i)
        {
            printf("%lld", mat[minRow][i]);
            if (i == n - 1){printf("\n");}
            else {printf(" ");}
        }
        avr[minRow] = 1000000;
    }
    return 0;
}