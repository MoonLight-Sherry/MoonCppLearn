#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(10);
    dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
    if (n <= 3){cout << dp[n] << endl; return 0;}
    for (int i = 4; i <= n; ++i)
    {
        int temp = dp[3];
        dp[3] = dp[1] + dp[2] + dp[3];
        dp[1] = dp[2], dp[2] = temp;
    }
    cout << dp[3] << endl;
    return 0;
}