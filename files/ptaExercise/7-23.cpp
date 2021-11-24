#include <stdio.h>
#include <string.h>
#define Max 100

void deleteStr(char* str, int len, int s2)
{
    for (int j = 0; j < len; ++j)
    {
        *str = *(str + s2);
        str++;
    }
}

int main()
{
    char str1[Max], str2[Max];
    scanf("%[^\n]", str1);
    getchar();
    gets(str2);
    size_t s1 = strlen(str1);
    size_t s2 = strlen(str2);
    int found = 1, count = 0;
    while(found)
    {
        for (int i = 0; i < s1 - s2; ++i)
        {
            found = 1;
            for (int j = 0; j < s2; ++j)
            {
                if (str1[i+j] != str2[j]){found = 0;}
            }
            if (found)
            {
                ++count;
                deleteStr(str1 + i, s1 - i - s2, s2);
                if (i >= s2 - 1)
                {
                     i -= s2 - 1;
                }
            }
        }
    }
    for (int i = 0; i < s1-s2*count; ++i)
    {
        printf("%c", str1[i]);
    }
    return 0;
}