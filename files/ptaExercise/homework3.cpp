#include <stdio.h>

int main()
{
    int cur, num, sum = 0, max = -1, min = 101;
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; ++i)
    {
        scanf("%d", &cur);
        sum += cur;
        if(cur > max) max = cur;
        if(cur < min) min = cur;
    }
    printf("%d %d %d\n", sum, max, min);
    return 0;
}