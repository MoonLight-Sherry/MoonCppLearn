#include <stdio.h>
#include <math.h>

int main()
{
    int present1[10] = {0}, present2[10] = {0};
    long long num;
    scanf("%lld", &num);
    int origin1 = num;
    if ((num / (long long)10e9) > 4 || num / (long long)10e10 != 0)
    {
        printf("No\n");
        printf("%lld\n", num * 2);
        return 0;
    }
    for (int i = 0; i < 9; ++i)
    {
        int cur = num % 10;
        if (present1[cur] == 0)
        {
            present1[cur] = 1;
            num /= 10;
        }
        else
        {
            printf("No\n");
            printf("%lld\n", origin1 * 2);
            return 0;
        }
    }

    long long origin2 = origin1*2;
    num = origin2;

    for (int i = 0; i < 9; ++i)
    {
        int cur = num % 10;
        if (present2[cur] == 0)
        {
            present2[cur] = 1;
            num /= 10;
        }
        else
        {
            printf("No\n");
            printf("%lld\n", origin2);
            return 0;
        }
    }
    printf("Yes\n");
    printf("%lld\n", origin2);
    return 0;
}