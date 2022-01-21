#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
     printf((n%8 == 2 || n%8 == 6)? "yes": "no");
     printf("\n");   
    }
    return 0;
}