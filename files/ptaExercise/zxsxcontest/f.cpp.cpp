#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    getchar();
    vector<int> c(n + 10, 0);
    for (int i = 0; i < n; ++i)
    {
        int cur;
        cin >> cur;
        c[i] = cur;
    }
    int dp[n + 10][m + 10] = {0};
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < m + 1; ++i)
    {
        dp[0][i] = (c[i] == i) ? c[0] : 0;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (c[i] < j)
            {
                if (dp[i - 1][j - c[i]] == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(c[i] + dp[i - 1][j - c[i]], dp[i - 1][j]);
                }
            }
            else if (c[i] == j)
            {
                dp[i][j] = max(c[i], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 1][m] <<endl;
}