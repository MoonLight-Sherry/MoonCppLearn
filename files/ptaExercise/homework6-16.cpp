#include<stdio.h>

void printFactor( int, int ); 

int isPrime(int num)
{
    if (num == 1) return 1;
    if (num <= 3) return 1;
    for (int i = 3; i * i <= num; ++i)
    {
        if (num % i == 0) return 0;
    }
    return 1;
}

void printFactor( int num, int n)
{
    if (n == 1) {printf("%d=", num);}
    if (isPrime(num)) { printf("%d\n", num); return;}
    int maxfac = 1;
    for (int i = 2; i*i <= num; ++i)
    {
        if (num%i==0) {maxfac = i; break;}
    }
    while ((maxfac != 1) && num%maxfac == 0){ printf("%d*", maxfac); num /= maxfac;}
    printFactor(num,2);
}

int main()
{
    int a,b,i ;

    scanf( "%d%d", &a, &b );
    for( i = a ; i <= b ; i++ )
        printFactor( i , 1 ) ;    

    return 0;
}

/* 请在这里填写答案 */

