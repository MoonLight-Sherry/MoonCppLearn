//卡特兰数！


class Solution {
public:
    long long c(long long i, long long j)
    {
        long long ans = 1;
        int divide = 1;
        for(int cur = i; cur > i - j; --cur)
        {
            ans *= cur;
            ans /= divide;
            ++divide;
        }
        return ans;
    }
    int numTrees(int n) {
        if (n == 1) return 1;
        return c((long long)2*n, (long long)n)- c ((long long)2*n, (long  long)(n-1));
    }
};