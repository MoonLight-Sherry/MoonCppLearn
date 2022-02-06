#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1, size = nums.size();
        for (int i = 0; i < size/2; ++i) {
            ans = max(ans, nums[i] + nums[size - i - 1]);
        }
        return ans;

    }
}; 