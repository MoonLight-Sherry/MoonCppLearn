#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int length = s.length();
        int curPos = 0;
        for (auto ch: pattern) {
            if (curPos >= length){
                return false;
            }
            int wordPos = curPos;
            while (wordPos < length && s[wordPos] != ' '){++wordPos;}
            const string &curWord = s.substr(curPos, wordPos - curPos);
            if (str2ch.find(curWord) != str2ch.end() && str2ch[curWord] != ch){return false;}
            if (ch2str.find(ch) != ch2str.end() && ch2str[ch] != curWord){return false;}
            str2ch[curWord] = ch;
            ch2str[ch] = curWord;
            curPos = wordPos + 1;
        }
        return curPos >= length;
    }
};