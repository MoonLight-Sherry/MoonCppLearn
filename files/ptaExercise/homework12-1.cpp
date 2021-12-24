#include<stdio.h>
#include<stdlib.h>

char ** create1(int n) ;
void create2( char ** strPtr , int n ) ;
void fill(char ** strPtr , int n) ;


int main()
{
    int        n, i, j;
    char**    strPtr ;

    scanf("%d", &n );
    strPtr = create1( n * 2 + 1 ) ;
    create2( strPtr ,  n * 2 + 1 ) ;
    fill(strPtr , n) ;

    for (i = 0; i < 2 * n + 1; i++)
    {
        printf("%s\n" , strPtr[i]);
    }

    for ( i = 0 ; i < n * 2 + 1 ; i++ )
    free(strPtr[i]) ;
    free(strPtr) ;

    return 0;
}



char ** create1(int n)
{
    char **parr = (char **)malloc(n * sizeof(char**));
    return parr;
}

void create2( char ** strPtr , int n )
{
    for (int i = 0; i < n; ++i)
    {
        strPtr[i] = (char*)malloc(n*sizeof(char*));
    }
}

void fill(char ** strPtr , int n)
{
    n = n*2+1;
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             strPtr[i][j] = ' ';
//         }
//     }
    
    for (int i = 0; i < (n - 1)/2; ++i)
    {
        for (int j = 0; j < (n-1)/2 - i; ++j)
        {
            strPtr[i][j] = ' ';
        }
        strPtr[i][(n-1)/2 - i] = '/';
        for (int j = (n-1)/2 - i + 1; j < (n-1)/2 + i; ++j)
        {
            strPtr[i][j] = ' ';
        }
        strPtr[i][(n-1)/2 + i] = '\\';
    }
    for (int k = (n - 1)/2 + 1; k < n; ++k)
    {
        for (int j = 0; j < -(n-1)/2 + k; ++j)
        {
            strPtr[k][j] = ' ';
        }
        strPtr[k][-(n-1)/2 + k] = '\\';
        for (int j = -(n-1)/2 + k + 1; j < (n-1)/2 + n - 1 - k; ++j)
        {
            strPtr[k][j] = ' ';
        }
        strPtr[k][(n-1)/2 + n - 1 - k] = '/';
    }
    for (int j = 0; j < (n-1)/2; ++j)
    {
        strPtr[n - 1][j] = ' ';
    }
        
    strPtr[(n-1)/2][0] = 'X';
    strPtr[(n-1)/2][n-1] = 'X';
    strPtr[0][(n-1)/2] = 'X';
    strPtr[n-1][(n-1)/2] = 'X';
    for (int i = 1; i < n - 1; ++i)
    {
        strPtr[(n-1)/2][i] = ' ';
    }
}