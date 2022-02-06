#include <iostream>
using namespace std;

int main()
{
    int input;
    while (cin >> input && input != -1){
        cout << (input & 1) << endl;
    }
    return 0;
}