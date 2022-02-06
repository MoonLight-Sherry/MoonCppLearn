#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long n;
    while (1)
    {
        cin >> n;
        if (n < 1)
        {
            cout << "Error" << endl;
            return 1;
        }
        vector<int> ans;
        if (n == 1){cout << "A" << endl; break;}
        n -= 1;
        while (n > -2)
        {
            ans.push_back(n % 26);
            n /= 26;
        }
        int size = ans.size();
        while (size--)
        {
            cout << char('A' + ans[size]);
        }
        cout << endl;
    }
    return 0;
}