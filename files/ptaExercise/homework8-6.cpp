#include <stdio.h>

int main()
{
    int n, max = 1;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = i; j < n; ++j)
        {
            if (nums[i] == nums[j]){++cur;}
            else {i = j - 1; break;}
        }
        max = max > cur? max : cur;
    }
    printf("%d\n", max);
}