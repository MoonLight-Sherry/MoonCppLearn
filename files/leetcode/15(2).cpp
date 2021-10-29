#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int length = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 2 && nums[i] <= 0; ++i)
        {
            int j = i + 1, k = length - 1;
            while(j < k)
            {
                if (nums[j] + nums[k] < -nums[i])
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    continue;
                }
                if (nums[j] + nums[k] < -nums[i]) ++j;
                if (nums[j] + nums[k] > -nums[i]) --k;
            }
            while(i < length - 3 && nums[i] == nums[i + 1]) ++i;
        }
        return ans;
    }
};