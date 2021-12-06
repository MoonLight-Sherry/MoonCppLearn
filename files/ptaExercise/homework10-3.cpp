#include <stdio.h>

void printArray(float arr[][5], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%.1f", arr[i][j]);
            if (j == col - 1){printf("\n");}
            else {printf("\t");}
        }
    }
}

int main()
{
    int note;
    scanf("%d", &note);
    float sale[6][5] = {0.0};
    int row = 6, col = 5;
    for (int i = 0; i < note; ++i)
    {
        getchar();
        int pro, man;
        float mon;
        scanf("%d%d%f", &pro, &man,&mon);
        sale[man - 1][pro  - 1] += mon;
    }
    for (int i = 0; i < row - 1; ++i)
    {
        for (int j = 0; j < col - 1; ++j)
        {
            sale[i][col - 1] += sale[i][j];
        }
    }
    for (int i = 0; i < col - 1; ++i)
    {
        for (int j = 0; j < row - 1; ++j)
        {
            sale[row -1][i] += sale[j][i];
        }
    }
    for (int i = 0; i < row - 1; ++i)
    {
        sale[row - 1][col - 1] += sale[i][col - 1];
    }
    printArray(sale, row, col);
}