#include <iostream>
using namespace std;

int gcd(long long x, long long y)
{
    return y == 0? x: gcd(y, x%y);
}

long long lcm(long long x, long long y)
{
    return x * y / gcd(x, y);
}

int main()
{
    long long n, x, y;
    cin >> n;
    getchar();
    while(n--)
    {
        int m;
        cin >> m;
        cin >> x;
        while(--m)
        {
            cin >> y;
            x = lcm(x, y);
        }
        cout << x << endl;
    }
    return 0;
}