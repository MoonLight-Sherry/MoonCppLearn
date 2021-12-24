#include <iostream>
using namespace std;

int main()
{
    int a[5][4] = {};
    a[2][3] = 23;
    cout << &a[0][3] - &a[0][0] << endl;
    cout << &a[0][1] << endl << &a[0][0] << endl;
    return 0;
}