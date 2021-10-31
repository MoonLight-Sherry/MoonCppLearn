#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[2] > b[2];
    }

    bool available(int event1, int event2, vector<vector<int>> &events)
    {
        return (events[event1][1] < events[event2][1] && events[event1][1] < events[event2][0]) || (events[event2][1] < events[event1][1] && events[event2][1] < events[event1][0]);
    }

    int maxTwoEvents(vector<vector<int>> &events)
    {
        {
            sort(events.begin(), events.end(), cmp);
            int ans = events[0][2];
            int length = events.size();
            for (int i = 0; i < length - 1; ++i)
            {
                for (int j = i; j < length; ++j)
                {
                    if (available(i, j, events))
                    {
                        ans = max(ans, events[i][2] + events[j][2]);
                        break;
                    }
                }
            }
            return ans;
        }
    }
};