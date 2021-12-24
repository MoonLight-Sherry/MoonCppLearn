#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur;
        cin >> cur;
        int a[10] = {0};
        for (int j = 0; cur; ++j)
        {
            a[j] = cur%2;
            cur /= 2;
        }
        if (a[2] == 1 && a[3] == 0)
        {
            num++;
        }
    }
    cout << num << endl;
    return 0;
}