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
            for (int j = i + 1; j < length - 1 && nums[i] + nums[j] <= 0; ++j)
            {
                if (find(nums.begin() + j + 1, nums.end(), -nums[i] - nums[j]) != nums.end())
                {
                    ans.push_back({nums[i], nums[j], nums[find(nums.begin() + j, nums.end(), -nums[i] - nums[j]) - nums.begin()]});
                }
            }
        }
        sort(ans.begin(), ans.end());
        // auto end_unique=unique(ans.begin(),ans.end()); 
        // ans.erase(end_unique,ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};