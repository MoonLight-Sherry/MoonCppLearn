#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> info(n);
        for (auto &t: times) {
            int x = t[0] - 1, y = t[1] - 1;
            info[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto cur = q.top();
            q.pop();
            int time = cur.first, index = cur.second;
            for (auto &e: info[index]){
                int next = e.first, newTime = dist[index] + e.second;
                if (newTime < dist[next]){
                    dist[next] = newTime;
                    q.emplace(newTime, next);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf? -1: ans;
    }
};