#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s1, s2;
    cin >> n >> s1;
    getchar();
    getline(cin, s2);
    string::size_type position = 0;
    while (n--)
    {
        position = s2.find(s1, position + 1);
    }
    if (position == s2.npos)
    {
        cout << "F" << endl;
        return 0;
    }
    int strlen = s1.length();
    for (int i = position; i < position + strlen; ++i)
    {
        if (s2[i] == 'z' || s2[i] == 'Z'){s2[i] = s2[i] - 25;}
        else
        {
            s2[i] = s2[i] + 1;
        }
    }
    cout << s2;
    return 0;
}