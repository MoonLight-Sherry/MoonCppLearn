#include <iostream>

using namespace std;

int main()
{
    char string1[10], *string2 = "hello", *string3;
    cout << string1 << " 1" << string2 << " 2" << sizeof(string2) << " 3" << sizeof(*string2) << " 4" << string3 << endl;
    return 0;
}