#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int cur;
        cin >> cur;
        int m = cur%4;
        cur = cur%10;
        if (m == 0){m = 4;}
        cout << (int)(pow(cur, m))%10 << endl;
    }
    return 0;
}