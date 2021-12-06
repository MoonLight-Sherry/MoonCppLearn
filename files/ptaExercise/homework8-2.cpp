#include <stdio.h>
#include <string.h>

int main()
{
    int m, n;
    scanf("%d", &n);
    getchar();
    int nums[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    getchar();
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int cur, find = -1;
        scanf("%d", &cur);
        for (int j = 0; j < n; ++j)
        {
            if (nums[j] == cur){find = j; break;}
        }
        if (find == -1){printf("NULL\n");}
        else if (find == 0){printf("%d", nums[1]);}
        else if (find == n - 2){printf("%d\n", nums[n - 1]);}
        else {printf("%d %d\n", nums[find - 1], nums[find + 1]);}
    }
}