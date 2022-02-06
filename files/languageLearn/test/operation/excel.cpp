#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n -= 1;
    if (n < 0)
    {
        cout << "Error" << endl;
        return 0;
    }
    cout << char('A' + n % 26);
    while (n / 26 != 0)
    {
         cout << char('A' + n / 26 - 1);
         n -= 26*26;
    }
    cout << endl;
    return 0;
}