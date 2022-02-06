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
        do
        {
            n -= 1;
            ans.push_back(n%26);
            n /= 26;
        } while (n);
        int size = ans.size();
        while (size--)
        {
            cout << char('A' + ans[size]);
        }
        cout << endl;
    }
    return 0;
}