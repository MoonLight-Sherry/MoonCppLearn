#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int dif = 0;
        if (sLen < pLen) {return vector<int>();}
        vector<int> count(26), ans;

        for (int i = 0; i < pLen; i++) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0){
                ++dif;
            }
        }
        if (dif == 0){
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; i++) {
            if (count[s[i] - 'a'] == 1) {--dif;}
            if (count[s[i] - 'a'] == 0) {++dif;}
            --count[s[i] - 'a'];

            if (count[s[i+pLen] - 'a'] == -1) {--dif;}
            if (count[s[i+pLen] - 'a'] == 0) {++dif;}
            ++count[s[i+pLen] - 'a'];

            if (dif == 0){ans.emplace_back(i+1);}
        }
        return ans;
    }
};