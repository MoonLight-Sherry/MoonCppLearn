#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x){
    int col = gridColSize[0];
    int len = gridSize * col, ans = 0;
    int arr[len];
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            arr[i*col + j] = grid[i][j];
            //arr[i*col + j] = *(*(gird + i) + j);
        }
    }
    qsort(arr, len, sizeof(arr[0]), compare);
    int mid = arr[len/2];
    for (int i = 0; i < len; ++i)
    {
        if ((arr[i] - mid)%x) return -1;
        else {ans += fabs((arr[i] - mid)/x);}
    }
    return ans;
}
