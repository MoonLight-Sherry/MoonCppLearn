#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int year;
        scanf("%d", &year);
        int cur = year - 844;
        printf("%d", cur%10);
        printf("%c\n", 'A' + cur%12);
    }
    return 0;
}