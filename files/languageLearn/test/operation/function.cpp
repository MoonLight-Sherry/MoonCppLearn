#include <iostream>
using namespace std;

void fun(char c, int a)
{
    cout << c;
    cout << endl;
    cout << a;
    a++;
}

int main()
{
    //fun(100, 'A');
    int a=3, b=4;
    cout << (a>b)+5-(a = b);
    return 0;
}