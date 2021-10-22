#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
    if (num == 1)
        return 0;
    if (num < 4)
        return 1;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, curnum;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        while (scanf("%d", &curnum) && curnum != -1)
        {
            cnt += isPrime(curnum);
        }
        getchar();
        printf("%d\n", cnt);
    }
    return 0;
}

//10min