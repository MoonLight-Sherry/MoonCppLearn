#include <stdio.h>

int main()
{
    float fa, ma, chi = 0;
    int flag;
    scanf("%f%f", &fa, &ma);
    scanf("%d", &flag);
    if (flag == 0)
    {
        chi = (ma + fa*0.923)/2;
    }
    else
    {
        chi = (fa + ma)*1.08/2;
    }
    printf("%.2f\n", chi);
    return 0;
}