#include <stdio.h>

int main()
{
    int even = 0, n;
    scanf("%d", &n);
    getchar();
    int num[n], ans[n + 1];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num[i]);
        if (!(num[i] % 2)){ans[even] = num[i];++even;}
    }
    for (int i = 0; i < n; ++i)
    {
        if (num[i]%2) {ans[even] = num[i]; ++even}
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", ans[i]);
    }
}