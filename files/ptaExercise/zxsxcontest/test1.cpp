#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int nums[15] = {0};
    for (int i = 0; i < num; ++i)
    {
        int cur;
        cin >> cur;
        int cnt = 0;
        if (cur == 0){cnt = 1;}
        while (cur != 0)
        {
            cnt++;
            cur /= 10;
        }
        nums[cnt]++;
    }
    for (int i = 1; i <= 10; ++i)
    {
        cout << nums[i] << endl;
    }
    return 0;
}