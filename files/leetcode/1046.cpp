#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    int smash(int stone1, int stone2)
    {
        return abs(stone1 - stone2);
    }

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, greater<int> > pstones;
        for (auto stone: stones)
        {
            pstones.push(stone);
        }
        while(pstones.size() > 1)
        {
            int stone1 = pstones.top();
            pstones.pop();
            int stone2 = pstones.top();
            pstones.pop();
            if(stone1 == stone2) continue;
            pstones.push(smash(stone1, stone2));
        }
        int ans = pstones.top();
        return ans;
    }

    int main()
    {
        vector<int> stones = {2,7,4,1,8,1};
        int ans = lastStoneWeight(stones);
        cout << ans << endl;
        return 0;
    }
};