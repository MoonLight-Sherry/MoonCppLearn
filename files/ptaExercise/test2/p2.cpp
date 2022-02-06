#include <stdio.h>

int main()
{
    int a, b;
    int num = 0;
    scanf("%d%d", &a, &b);
    if ((b% 7 == 0 && a%7!= 0) || (b%7 != 0 && a%7 == 0))
    {
        num = (b - a)/7 - 1;
    }
    else if (a % 7 == 0 && b%7 == 0)
    {
        num = (b - a)/7 - 2;
    }
    else{
        num = (b - a)/7;
    }
    printf("%d\n", num);
    return 0;
}