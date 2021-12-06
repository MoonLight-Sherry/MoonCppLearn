#include <stdio.h>

int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    int mat[row][col];
    int rev[col][row];
    for (int i = 0; i < row; ++i)
    {
        getchar();
        for (int j = 0; j < col; ++j)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < col; ++i)
    {
        for (int j = i; j < row; ++j)
        {
            rev[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            printf("%d", mat[j][i]);
            if (j == row - 1){printf("\n");}
            else {printf(" ");}
        }
    }
    return 0;
}