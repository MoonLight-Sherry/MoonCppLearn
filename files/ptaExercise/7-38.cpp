#include <stdio.h>
#include <math.h>

long long getSum(long long A, long long N)
{
    if(N <= 0)
    {
        return 0;
    }
    return (long long)(pow(10, N)-1)/9*A + getSum(A, N-1);
}


int main()
{
    long long A, N;
    scanf("%lld%lld", &A, &N);
    printf("%lld\n", getSum(A, N));
    return 0;
}