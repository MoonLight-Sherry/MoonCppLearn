#include <stdio.h>
#include <math.h>

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main()
{
    int n;
    scanf("%d", &n);
    int cow[n + 10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cow[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int cur = (cow[i] * cow[i - 1]) / gcd(cow[i], cow[i-1]);
        cow[i] = cur;
    }
    printf("%d\n",cow[n - 1]);
}