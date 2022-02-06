#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double result(double x)
{
    double ans = 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
    printf("%.10llf", x);
    cout << "x: " << x << ", ans: " << ans << endl;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double sum;
        cin >> sum;
        if (sum < 0 || sum > result(100))
        {
            cout << "No sulution!" << endl;
            continue;
        }
        double left = 0;
        double right = 100;
        int flag = 1;
        time_t start, end;
        time(&start);
        int times = 0;
        while (left < right && flag)
        {
            double mid = (left + right) / 2;
            double curResult = result(mid);
            if (abs(curResult - sum) < 1e-4)
            {
                // = round(mid*10000)/10000;
                printf("%.4lf\n", mid);
                flag = 0;
                break;
            }
            else if (curResult < sum)
            {
                left = mid + 1e-8;
            }
            else
            {
                right = mid - 1e-8;
            }
            ++times;
        }
        time(&end);
        cout << "spend:" << difftime(end, start) << endl << "times:" << times <<endl;
        if (flag)
        {
            cout << "No sulution!" << endl;
        }
    }
    return 0;
}