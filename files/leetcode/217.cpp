#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> times;
        for (int num: nums){
            if (times.find(num) != times.end() && times[num] >= 1){
                return true;
            }
            if (times.find(num) == times.end()){
                times.emplace(num, 1);
            }
            else{
                ++times[num];
            }
        }
        return false;
    }
};