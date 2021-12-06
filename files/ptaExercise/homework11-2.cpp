#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define        MAXLEN        110

int        isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0 
int        getResult( char word[] ) ;

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}


int getResult( char word[] )
{
    int max, min;
    int *fre = (int *)malloc(26*sizeof(int));
    memset(fre, 0, 26*sizeof(int));
    for (int i = 0; i <= strlen(word); ++i)
    {
        fre[word[i] - 'a']++;
    }
    min = 1, max = 1;
    for (int i = 0;  i < 26; ++i)
    {
        min = (min > fre[i] && fre[i] > 0)? fre[i]: min;
        max = max > fre[i]? max: fre[i];
    }
    return isPrime(max - min) == 1? max - min : -1;
}