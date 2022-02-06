#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    bool match(const string &a, const string &b){
        if (a.size() != b.size() - 1){
            return false;
        }

        int i = 0;
        for (int j = 0; j < b.size() && i < a.size(); ++j){
            if (a[i] == b[j]){
                ++i;
            }
        }
        return i == a.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });

        int n = words.size();
        int d[n];
        for (int i = 0; i < n; ++i)
        {
            d[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (match(words[j], words[i])){
                    d[i] = max(d[i], d[j] + 1);
                }
            }
            ans = max(ans, d[i]);
        }
        return ans;
    }

};