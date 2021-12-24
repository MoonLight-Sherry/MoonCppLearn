#include <stdio.h>

int main()
{
    long long A, N;
    scanf("%lld%lld", &A, &N);

    if (N == 0)
    {
        printf("0");
        return 0;
    }

    int sum[100003];
    int digit = 0;
    for (int i = 0; i < N; ++i)
    {
        sum[i] = (digit + (A*(N-i)))%10;
        digit = (digit + (A*(N-i)))/10;
    }
    int count = -1;
    while(digit)
    {
        ++count;
        sum[N+count] = digit%10;
        digit /= 10;
    }
    for (int i = N + count; i >= 0; --i)
    {
        printf("%d", sum[i]);
    }
    return 0;

}