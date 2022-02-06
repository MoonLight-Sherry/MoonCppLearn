#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        int size = words.size();
        for (int cur = 0; cur < size;) {
            int curLen = 0, num = 0;
            while (cur + num < size && curLen + words[cur + num].size() <= maxWidth) {
                curLen += words[cur + num].size() + 1;
                ++num;
            }
            string curWord = string(maxWidth, ' ');
            if (num == 1 || cur + num == size) {
                int beginIndex = 0;
                for (int i = 0; i < num; ++i) {
                    for (int j = 0; j < words[cur + i].size(); ++j) {
                        curWord[beginIndex + j] = words[cur + i].at(j);
                    }
                    beginIndex += words[cur + i].size() + 1;
                }
                output.push_back(curWord);
                break;
            }
            int beginIndex = maxWidth, sumWordsLen = 0;
            for (int i = 0; i < num; ++i) {
                sumWordsLen += words[cur + i].size();
            }
            int sumSpaceLen = maxWidth - sumWordsLen;
            int num1 = num - 1;
            do{
                beginIndex -= words[cur + num1].size();
                for (int j = 0; j < words[cur + num1].size(); ++j){
                    curWord[beginIndex + j] = words[cur + num1].at(j);
                }
                if (num1 > 0){
                    beginIndex -= sumSpaceLen/num1;
                    sumSpaceLen -= sumSpaceLen/num1;
                }
            }while(num1--);
            output.push_back(curWord);
            cur += num;
        }
        return output;
    }
}solution;

int main(){
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> output = solution.fullJustify(words, maxWidth);
    return 0;
}