#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        for (int curIndex = 0; curIndex < size; ++curIndex) {
            int curLen = 0, curNum = nums[curIndex];
            while (curIndex < size && nums[curIndex] == curNum){
                ++curLen;
                ++curIndex;
            }
            --curIndex;
            while (curLen > 2){
                nums.erase(nums.begin() + curIndex);
                --curLen, --curIndex, --size;
            }
        }
        return size;
    }
};