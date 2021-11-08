#include <string>
#include <stack>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        char cur;
        int length = s.length();
        stack<char> stk;
        map<char,char> pairs {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (int i = 0; i < length; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else if (!stk.empty() && stk.top() == pairs[s[i]])
            {
                stk.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        if(!stk.empty()){ans = false;}
        return ans;
    }

    int main()
    {
        string s = "()";
        return isValid(s);
    }
};