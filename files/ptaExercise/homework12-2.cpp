#include <stdio.h>

int cmp(char* str, int index1, int index2)
{
    while(str[index1] == str[index2] && str[index1] - '0' != 0 && str[index2] - '0' != 0)
    {
        index2++;index1++;
    }
    if (str[index2] == str[index1] && str[index1] == 0) return 0;
    if (str[index1] < str[index2]) return -1;
    else return 1;
}

int main()
{
    char str[100000];
    int pointer[150];
    int prefix[150];
    pointer[0] = 0;
    prefix[0] = 0;
    int n;
    scanf("%d", &n);
    getchar();
    int curcount = 0;
    for (int i = 0; i < n; ++i)
    {
        char cur;
        int count = 0;
        while(scanf("%c", &cur) && cur != '\n')
        {
            str[curcount + count] = cur;
            count++;
        }
        str[curcount+count] = '0';
        count++;
        pointer[i + 1] = count;
        curcount += count;
        prefix[i + 1] = curcount;
    }
    for (int i = 0; i < n; ++i)
    {
        int k = 0;
        while(pointer[k] == -1){++k;}
        int minIndex = k;
        for (int i = 0; i < n; ++i)
        {
            if (pointer[i] == -1){continue;}
             minIndex = cmp(str, prefix[minIndex], prefix[i]) > 0? i:minIndex;
        }
        for (int j = prefix[minIndex]; j < prefix[minIndex+1] - 1; ++j)
        {
            printf("%c", str[j]);
        }
        printf("\n");
        pointer[minIndex] = -1;
    }
    return 0;
}