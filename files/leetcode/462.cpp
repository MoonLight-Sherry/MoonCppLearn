#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
    
int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0, size = nums.size();
    int mid = nums[(size - 1)/2];
    for(int i = 0; i < size; ++i)
    {
        sum += abs(nums[i] - mid);
    }
    return sum;
}



int main() {
    vector<int> nums {1,2};
    int ans = minMoves2(nums);
    cout << ans << endl;
    return 0;
}