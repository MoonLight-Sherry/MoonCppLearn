#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> numsMap;
        vector<int> missing;
        int length = nums.size();

        for (auto num: nums)
        {
            ++numsMap[num];
        }
        for (auto [num, time]: numsMap)
        {
            if (time == 1)
            {
                missing.push_back(num);
            }
        }
        return missing;
    }
};