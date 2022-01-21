#include <stdio.h>
#include <math.h>

int main()
{
    double a0, a1, a2, a3;
    scanf("%lf%lf%lf%lf", &a0, &a1, &a2, &a3);
    double a, b;
    scanf("%lf%lf", &a, &b);
    double left = a, right = b;
    while(left <= right)
    {
        double mid = (left + right) / 2;
        double cur = a0*pow(mid, 3) + a1*pow(mid, 2) + a2*pow(mid, 1) + a3*pow(mid,0);
        if (cur <= 1e-6 && cur >= -1e-6){printf("%.2lf", mid); return 0;}
        double leftSum = a0*pow(left, 3) + a1*pow(left, 2) + a2*pow(left, 1) + a3*pow(left, 0);
        if (cur * leftSum < 0){right = mid;}
        else{left = mid;}
    }
    return 0;
}