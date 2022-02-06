#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        if (a == 0 || b == 0) {break;}
        a = a%1000;
        int ans = a;
        while(--b)
        {
            ans = (ans*a)%1000;
        }
        cout << ans << endl;
    }
    return 0;
}