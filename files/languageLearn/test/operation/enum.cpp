#include <iostream>
using namespace std;
enum months {January = 1,February,March,April,May,June,July,August = 13,September,October,November,December};

int main()
{
    enum months month1;
    int month = month1;
    for (month = January; month <= December; month++)
    {
        cout << month << endl;
    }
    return 0;
}