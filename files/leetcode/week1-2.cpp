//failed

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int find(int n)
    {
        vector<int> possible = {1, 22, 122, 121, 221, 1333, 3133, 3313, 3331, 4444, 22333, 14444, 23233, 23323, 23332, 32233, 32323, 32332, 33223, 33232, 33322,41444, 44144, 44414, 44441, 55555};
        int i = 0;
        for(; i < possible.size(); ++i)
        {
            if(n > possible[i]) ++i;
            else break;
        }
        return possible[i];
    }

    int nextBeautifulNumber(int n) {
        
        int ans = find(n);
        return ans;
    }




    int main()
    {

    }
};