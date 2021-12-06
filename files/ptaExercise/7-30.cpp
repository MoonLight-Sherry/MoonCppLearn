#include <stdio.h>
#include <string.h>

void swap (char *a, char *b)
{
    char temp[15] = {};
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int main()
{
    int N, K;
    scanf("%d%d", &N,&K);
    char words[110][15] = {};
    for (int i = 0; i < N; ++i)
    {
        gets(words[i]);
    }
    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (strcmp(words[j], words[j+1]) > 0)
            {
                swap(words[j], words[j+1]);
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        puts(words[i]);
    }
    return 0;
}