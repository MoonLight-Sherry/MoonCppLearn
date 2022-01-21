#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int a[3][4] = {0};
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = count++;
        }
    }
    int (*p1)[4] = a + 1;
    // int *p = a[0];
    // while(*p)
    // {
    //     cout << *p << endl;
    //     p++;
    // }
    return 0;
}