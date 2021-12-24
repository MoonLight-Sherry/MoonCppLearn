#include <stdio.h>

int main()
{
    char str[30];
    int scanfNum = scanf("%s", str);
    int putsNum = puts(str);
    printf("\n\n%d\n%d\n", scanfNum, putsNum);
}