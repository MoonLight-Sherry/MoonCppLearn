//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <math.h>
#include <iomanip>

using namespace std;

bool isGreater(vector<double> a, vector<double> b)
{
    return a[2] > b[2];
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (m == -1 || n == -1)
        {
            break;
        }
        vector<vector<double>> change(n, vector<double>(3, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> change[i][0] >> change[i][1];
            if (abs(change[i][1]) < 1e-8)
            {
                change[i][2] = numeric_limits<int>::max();
            }
            else
            {
                change[i][2] = change[i][0] / change[i][1];
            }
        }
        sort(change.begin(), change.end(), isGreater);
        double ans = 0.0;
        int curIndex = 0;
        // integral parts
        while (curIndex < n && m >= change[curIndex][1])
        {
            ans += change[curIndex][0];
            m -= change[curIndex][1];
            curIndex++;
        }
        // left parts
        if (curIndex < n && m > 0)
        {
            ans += change[curIndex][2] * m;
        }
        ans = round(ans*1000)/1000;
        //cout << setprecision(3) << showpoint << fixed <<  ans << endl;
        printf("%.3lf\n", ans);
    }
    return 0;
}