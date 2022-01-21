#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if (n == 0) {break;}
        vector<int> tianji, king;
        for(int i=0; i<n; i++)
        {
            int cur;
            cin >> cur;
            tianji.push_back(cur);
        }
        for(int i=0; i<n; i++)
        {
            int cur;
            cin >> cur;
            king.push_back(cur);
        }
        sort(tianji.begin(), tianji.end());
        sort(king.begin(), king.end());
        int ans = 0;
        int index = 0;
        for(int i = 0; i < n && index < n; i++)
        {
            while(index < n && tianji[index] <= king[i])
            {
                ++index;
            }
            if (index < n && tianji[index] > king[i])
            {
                ans += 1;
                ++index;
            }
        }
        cout << (2*ans - n) * 200 << endl;
    }
    return 0;
}