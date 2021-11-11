#include <vector>
using namespace std;


class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startValue = 1;
        int sum = 1;
        for(auto num: nums)
        {
            sum += num;
            int add = sum>=1? 0 : 1-sum;
            startValue += add;
            sum += add;
        }
        return startValue;
    }
};