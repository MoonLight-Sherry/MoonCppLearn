#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int remain = n;
    int wage[7] = {100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 7 && remain; ++i)
    {
        int num = remain/wage[i];
        if (!num) {remain -= num*wage[i];printf("%d:%d\n", wage[i], num);}
    }
    printf("\n");
}