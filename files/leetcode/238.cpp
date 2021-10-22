#include <vector>
#include <iostream>
using namespace std;


 vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	if (n < 2) return nums;
    if (n < 3){
        swap(nums[0], nums[1]);
        return nums;
    }
	vector<int> forward(n, 1), backward(n, 1), ans(n, 1);
	forward[0] = nums[0];
	backward[n - 1] = nums[n - 1];

	for (int i = 1; i < n; ++i)
	{
		forward[i] = nums[i] * forward[i - 1];
	}
	for (int i = n - 2; i > -1; --i)
	{
		backward[i] = nums[i] * backward[i + 1];
	}

	ans[0] = backward[1];
	ans[n - 1] = forward[n - 2];
	for (int i = 1; i < n - 1; ++i)
	{
		ans[i] = forward[i - 1] * backward[i + 1];
	}
	return ans;
 }

int main() {
	vector<int> nums = { 1,2,3,4 };
	vector<int> ans = productExceptSelf(nums);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << ans[i] << endl;
	}
    return 0;
}