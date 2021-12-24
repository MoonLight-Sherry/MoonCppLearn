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
    vector<vector<int>> dp(n+2, vector<int>(m+1, 0));
    dp[0][0] = c[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - c[i - 1]] + c[i]);
        }
        
    }

}