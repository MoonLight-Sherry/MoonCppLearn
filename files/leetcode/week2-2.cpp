#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int count(int event1, int event2, vector<vector<int>>& events)
    {
        int time = 0;
        if ((events[event1][1] < events[event2][1] && events[event1][1] < events[event2][0]) || (events[event2][1] < events[event1][1] && events[event2][1] < events[event1][0]))
        {
            time = events[event1][2] + events[event2][2];
        }
        else
        {
            time = max(events[event1][2], events[event2][2]);
        }
        return time;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        int maxTime = 0;
        int length = events.size();
        for (int i = 0; i < length - 1; ++i)
        {
            for(int j = i + 1; j < length; ++j)
            {int time = count(i, j, events);
            maxTime = max(time, maxTime);
            }
        }
        return maxTime;
    }
};