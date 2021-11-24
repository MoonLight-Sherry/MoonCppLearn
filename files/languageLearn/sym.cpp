#include <stdio.h>

int reverse(int num)
{
    if (num/10 == 0)
    {
        return num%10;
    }
    return  reverse(num/10);
}

int main()
{
    int num1 = 12343211;
    int num2 = 12321;
    if (reverse(num1) == num1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    if (reverse(num2) == num2)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}