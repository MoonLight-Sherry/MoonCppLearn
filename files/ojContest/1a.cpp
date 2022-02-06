#include <iostream>
using namespace std;

int gcd(int x, int y) {
    return y == 0? x: gcd(y, x%y);
}

int lcm(int x, int y) {
    return x * y /gcd(x, y);
}

int main()
{
    int x, y;
    while(cin >> x >> y)
    {
        cout << lcm(x, y) << endl;
    }
    return 0;
}