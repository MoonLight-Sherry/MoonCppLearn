#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int mat[n + 1][n + 1];
    mat[1][1] = 1;
    int dir = -1;
    for (int i = 2;  i <= n; ++i)
    {
        if (dir == -1) 
        {
            int count1 = i, count2 = 1;
            for (int j = (i-1)*i/2+1; j <= (i+1)*i/2; ++j, --count1, ++count2)
            {
                
                mat[count1][count2] = j;
            }
        }
        if (dir == 1) 
        {
            int count1 = 1, count2 = i;
            for (int j = (i-1)*i/2+1; j <= (i+1)*i/2; ++j, ++count1, --count2)
            {
                
                mat[count1][count2] = j;
            }
        }
        dir *= -1;
    }

    for (int i = 2;  i <= n; ++i)
    {
        for (int j = n - i + 2; j <= n; ++j)
        {
            mat[i][j] = n*n+1 - mat[n+1-i][n+1-j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d", mat[i][j]);
            if (j != n){printf(" ");}
            else {printf("\n");}
        }
    }
    return 0;
}













