#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n, x0;
    cin >> n >> x0;
    getchar();
    long long sum = 0;
    for (int i = n; i > 0; --i)
    {
        long long cur;
        cin >> cur;
        sum += cur * i * (long long)pow(x0, i - 1);
    }
    cout << sum << endl;
    return 0;
}