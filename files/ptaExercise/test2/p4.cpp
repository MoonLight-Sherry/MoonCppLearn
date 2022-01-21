#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m, n, c;
    scanf("%d%d%d", &m, &n, &c);
    int mat[m+5][n+5];
    for (int i = 0; i <m + 5; i++)
    {
        memset(mat[i], 0, sizeof(mat[i]));
    }
    while(c--){
        int row, col;
        scanf("%d%d", &row, &col);
        for (int i = row - 1; i <=row + 1; ++i)
        {
            for (int j = col - 1; j <= col + 1; ++j)
            {
                mat[i][j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (mat[i][j] == 1)
            {
                ++count;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}