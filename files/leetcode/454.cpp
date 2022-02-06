#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> countAB;
        for (int a: nums1) {
            for (int b: nums2) {
                ++countAB[a+b];
            }
        }
        int ans = 0;
        for (int c: nums3) {
            for (int d: nums4) {
                if (countAB.count(-c-d)){
                    ans += countAB[-c-d];
                }
            }
        }
        return ans;
    }
};