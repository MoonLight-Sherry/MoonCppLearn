#include <stdio.h>
#include <string.h>

int main()
{
    char str[50000][15];
    int count = 0;
    char cur;
    while(cur = getchar() && cur != '\n')
    {
        ungetc(cur, stdin);
        scanf("%s", str[count]);
        while(cur = getchar() && cur == ' '){}
        ungetc(cur, stdin);
        ++count;
    }
    while(count--)
    {
        puts(str[count]);
        puts(" ");
    }
    return 0;
}