#include <stdio.h>
#include <math.h>

int main()
{
    int n, ans = 0, digit = 0;
    scanf("%d", &n);
    int m = n;
    while(m)
    {
        ++digit;
        m /= 10;
    }
    int k = 1;
    for(; k <digit; ++k)
    {
        ans += k * (int)(pow(10, k) - (int)pow(10, k-1));
    }
    ans += k * (n - (int)pow(10, k- 1) + 1);
    printf("%d\n", ans);
    return 0;
}


//20min