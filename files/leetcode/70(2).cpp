

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1){
            return 1;
        }
        int result[2] = {1, 1};
        while(--n){
            int cur = result[1];
            result[1] += result[0];
            result[0] = cur;
        }
        return result[1];
    }
};