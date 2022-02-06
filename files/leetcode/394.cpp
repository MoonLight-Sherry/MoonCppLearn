#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> letters;
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                string curTime = "";
                curTime += c;
                while (isdigit(s[i+1])) {
                    ++i;
                    curTime += s[i];
                }
                letters.push(curTime);
            }
            else if (isalpha(c)){
                string curString = "";
                curString += c;
                while (isalpha(s[i + 1])){
                    ++i;
                    curString += s[i];
                }
                letters.push(curString);
            }
            else if (c == '['){
                letters.push("[");
            }
            else if (c == ']'){
                string formerstr = "";
                stack<string> former;
                while (letters.top() != "["){
                    former.push(letters.top());
                    letters.pop();
                }
                while (!former.empty()){
                    formerstr += former.top();
                    former.pop();
                }
                letters.pop();
                int time = stoi(letters.top());
                letters.pop();
                string latterstr;
                while(time--){
                    latterstr += formerstr;
                }
                letters.push(latterstr);
            }
        }
        string ans = "";
        stack<string> reverse;
        while (!letters.empty()){
            reverse.push(letters.top());
            letters.pop();
        }
        while (!reverse.empty()){
            ans += reverse.top();
            reverse.pop();
        }
        return ans;
    }
}solution;

int main(){
    string s = "2[abc]3[cd]ef";
    cout << solution.decodeString(s) << endl;
    return 0;
}

