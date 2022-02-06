#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumIndex;
        int count = 0, size = nums.size(), ans = -1;
        sumIndex[count] = -1;
        for (int i = 0; i < size; ++i) {
            count += (nums[i] == 0? -1: 1);
            if (sumIndex.count(count)){
                ans = max(ans, i - sumIndex[count]);
            }
            else{
                sumIndex[count] = i;
            }
        }
        return ans;
    }
};