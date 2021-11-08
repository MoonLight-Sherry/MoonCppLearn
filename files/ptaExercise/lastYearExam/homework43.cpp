#include <stdio.h>

int count(int i)
{
    int cnt = 0;
    while(i)
    {
        cnt += (i%10)*(i%10);
        i /= 10;
    }
    return cnt;
}


int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i =1; i < n; ++i)
    {
        if((i/m) == count(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}