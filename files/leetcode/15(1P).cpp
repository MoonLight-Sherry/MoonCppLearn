#pragma once
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < length - 2 && nums[i] <= 0; ++i)
        {
            for (int j = i + 1; j < length - 1 && nums[i] + nums[j] <= 0; ++j)
            {
                if (find(nums.begin() + j + 1, nums.end(), -nums[i] - nums[j]) != nums.end())
                {
                    ans.push_back({ nums[i], nums[j], nums[find(nums.begin() + j, nums.end(), -nums[i] - nums[j]) - nums.begin()] });
                }
            }
        }
        cout << "before unique:" << endl;
        printoutItems(ans.begin(), ans.end());
        cout << endl;
        auto endptr = unique(ans.begin(), ans.end());
        cout << "After unique:" << endl;
        printoutItems(ans.begin(), endptr);
        cout << endl;

        ans.erase(endptr, ans.end());
        printoutItems(ans.begin(), ans.end());
        return ans;

    }
private :
    void printoutItems(vector<vector<int>>::iterator begin, vector<vector<int>>::iterator end) {

        cout << "begin output:" << endl;
        for (vector<vector<int>>::iterator itr = begin; itr < end; ++itr) {
            vector<int> aItr = *itr;
            for (vector<int>::iterator bItr = aItr.begin(); bItr < aItr.end(); ++bItr) {
                cout << *bItr << ", ";
            }
            cout << endl;
        }
        cout << "output all." << endl;

    }

};