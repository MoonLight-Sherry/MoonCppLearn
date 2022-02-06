#include <stdio.h>

int main()
{
    int a, b;
    int num = 0;
    scanf("%d%d", &a, &b);
    for (int i = a + 1; i < b; ++i)
    {
        int cur = i;
        if (i % 7 == 0)
        {
            ++num;
            continue;
        }
        else
        {
            while (cur > 0)
            {
                if (cur % 10 == 7)
                {
                    ++num;
                    
                    break;
                }
                cur /= 10;
            }
        }
    }
    printf("%d\n", num);
    return 0;
}