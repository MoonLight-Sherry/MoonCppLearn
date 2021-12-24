#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(char* str1, char* str2)
{
    while(*str1 && *str2 && *str1 == *str2)
    {
        ++str1, ++str2;
    }
    return *str1 - *str2;
}

void printResult(char** str, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%s\n", *(str + i));
    }
}

int main()
{
    int n;
    char buffer[1000];
    scanf("%d", &n);
    getchar();
    char *pointers[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%[^\n]", &buffer);
        getchar();
        int len = strlen(buffer);
        char *cur = (char*)malloc(sizeof(char)*len);
        for (int i = 0; i < len; ++i)
        {
            *(cur + i) = *(buffer + i);
        }
        
        pointers[i] = cur;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (cmp(pointers[i], pointers[j]) < 0)
            {
                char* temp = pointers[i];
                pointers[i] = pointers[j];
                pointers[j] = temp;
            }
        }
    }

    printResult(pointers, n);
    return 0;
}