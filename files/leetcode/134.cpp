//time limit exeed
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possible(int i, vector<int> &v)
    {
        int size = v.size();
        int sum = 0;
        for (int count = 0; count < size; count++)
        {
            sum += v[(i + count)%size];
            if (sum < 0){return false;}
        }
        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        vector<int> profit(size);
        for(int i = 0; i < size; i++)
        {
            profit[i] = gas[i] - cost[i];
        }
        if (accumulate(profit.begin(), profit.end(), 0) < 0){return -1;}
        for(int i = 0; i < size;)
        {
            while (profit[i] < 0){++i;}
            if (possible(i, profit)){return i;}
        }
        return -1;
    }
};