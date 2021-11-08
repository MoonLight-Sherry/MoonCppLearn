#include <vector>
#include <string>
#include <iostream>
using namespace std;

void mul(string num, int cur, vector<vector<string>> &sum, int i)
{
    int carry = 0;
    for (int j = 0; j < num.length(); ++j)
    {
        cout << carry << " ";
        int pre = cur * (num[j] - '0');
        sum[i][j + i] = std::to_string((pre + carry) % 10);
        cout << pre + carry << endl;
        if (pre + carry > 9)
        {
            carry = (pre + carry) / 10;
        }
        else
        {
            carry = 0;
        }
    }
    sum[i][num.length()] = to_string(carry);
}

int main()
{
    vector<vector<string>> sum(50, vector<string>(50, ""));
    string num1 = "123", num2 = "923";
    for (int i = num2.length() - 1; i > -1; --i)
    {
        mul(num1, num2[i] - '0', sum, num2.length()-1-i);
    }
    return 0;
}