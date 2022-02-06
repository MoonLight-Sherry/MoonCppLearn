#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<vector<int>> tables;
        while (N--)
        {
            int from, to;
            cin >> from >> to;
            if (from > to){swap(from, to);}
            tables.push_back({from, to});
        }
        sort(tables.begin(), tables.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        int ans = 0;
        while(!tables.empty())
        {
            vector<int> cur = *(tables.begin());
            tables.erase(tables.begin());
            if (tables.empty()){ans += 1; break;}
            ans += 1;
            vector<vector<int>>::iterator it = tables.begin();
            while(it != tables.end())
            {
                if (((*it)[0] + 1) / 2 > (cur[1] + 1)/ 2)
                {
                    cur = *it;
                    it = tables.erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }
        cout << ans * 10 << endl;
    }
    return 0;
}