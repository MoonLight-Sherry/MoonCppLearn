#include <stdio.h>

int main()
{
    int value, num, cnt = 0;
    scanf("%d%d", &value, &num);
    for(int i = 0; i <= value/5; ++i)
    {
        for(int k = 0; k <= (value - 5*i)/2; ++k)
        {
            int j = num - i - k;
            if (value == 5*i + 2*k + j) ++cnt;
        }
    }
    printf("%d", cnt);
    return 0;
}

//10min