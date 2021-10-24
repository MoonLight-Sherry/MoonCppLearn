//摩尔算法需要选票超过人数一半

using namespace std;

int majorityVote(int nums[]){
        int m = 0;
        int count = 0;
 
        for (int k = 0; k < 9; ++k) {
            int i = nums[k];
            if (count == 0) {
                m = i;
                count++;
            } else if (i == m) {
                count++;
            } else {
                count--;
            }
        }
        return m;
}

int main()
{
    int nums[8] = {2, 1, 3, 3, 2, 2, 1, 4};
    int ans = majorityVote(nums);
    return 0;
}