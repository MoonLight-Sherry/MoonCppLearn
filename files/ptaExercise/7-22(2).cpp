#include <stdio.h>
#include <string.h>
char s1[100], s2[100];

int main()
{
    gets(s1);
    gets(s2);
    int len = strlen(s2);
    char *l;
    while (l = strstr(s1, s2))
    {
        for (int i = 0; *(l + i); ++i)
        {
            *(l + i) = *(l + len + i);
        }
    }
    puts(s1);
    return 0;
}