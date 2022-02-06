#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int find(int n, vector<int> &rp)
    {
        int num = n;
        while(rp[num] != num)
        {
            num = rp[num];
        }
        return num;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> rp(1001);
        int size = edges.size();
        for (int i = 0; i < size; i++)
        {
            rp[i] = i;
        }
        for (int j = 0; j < size; j++)
        {
            int set1 = find(edges[j][0], rp);
            int set2 = find(edges[j][1], rp);
            if (set1 == set2)
            {
                return edges[j];
            }
            else
            {
                rp[set1] = set2;
            }
        }
        return {0, 0};
    }
};