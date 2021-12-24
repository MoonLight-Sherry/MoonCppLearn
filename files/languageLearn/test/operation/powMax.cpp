#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int powMax1, powMax2;
    powMax1 = pow(3,int(log(INT_MAX)/log(3)));
    cout << powMax1;
}