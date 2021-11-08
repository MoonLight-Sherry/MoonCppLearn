#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int length = events.size();
        vector<vector<int>> dp(2,vector<int>(length));
        for (int i = 1; i < length; ++i)
        {
            dp[0][i] = max(dp[0][i-1], events[0][i]);
            if (i >= events[i][1] - events[i][0] && dp[0][i - (events[i][1] - events[i][0])] + events[i][2] > dp[1][i - 1])
            {
                dp[1][i] =  dp[0][i - (events[i][1] - events[i][0])] + events[i][2];
            }
            else
            {
                dp[1][i] = dp[1][i - 1];
            }
        }
        return max(dp[0][length - 1], dp[1][length - 1]);
    }
};