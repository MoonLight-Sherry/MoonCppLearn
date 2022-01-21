#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5, b = 10;
    a ^= b ^= a ^= b;
    cout << a << " " << b << endl;
    return 0;
}