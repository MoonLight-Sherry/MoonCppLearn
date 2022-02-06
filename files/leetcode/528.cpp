#include <bits/stdc++.h>
using namespace std;


class Solution {
    mt19937 m;
    vector<int> prefixSum;

public:
    Solution(vector<int>& w) {
        int size = w.size();
        for (int i = 1; i < size; ++i){
            prefixSum[i] = prefixSum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int sum = prefixSum.back();
        srand(time(NULL));
        int randNum = rand() % sum + 1;
        return lower_bound(prefixSum.begin(), prefixSum.end(),randNum) - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */