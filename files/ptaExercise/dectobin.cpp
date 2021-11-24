#include <stdio.h>

int dectobin( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", dectobin(n));

    return 0;
}


int dectobin( int n )
{
    if (n <= 1)
    {
        return n;
    }
    return n % 2 + 10 * dectobin(n/2);
}