#include <stdio.h>

int main(){
    double temp;
    char space, mode;
    scanf("%lf%c%c", &temp, &space, &mode);
    if(mode == 'C')
    {
        if(temp < -273.15)
        {
            printf("Invalid\n");
            return 0;
        }
        else temp = temp * 1.8 + 32;
        printf("%.2lf F\n", temp);
    }
    else if (mode == 'F')
    {
        temp = (temp - 32)/1.8;
        if (temp < 0)
        {
            printf("Invalid\n");
            return 0;
        }
        printf("%.2lf C\n", temp);
    }
    return 0;
}