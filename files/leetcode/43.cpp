#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void mul(string num, int cur, vector<vector<string>>& sum, int i)
    {
        int carry = 0;
        for (int j = 0; j < num.length(); ++j)
        {
            int pre = cur * (num[j] - '0');
            sum[i][j + i] = std::to_string((pre + carry) % 10);
            if (pre + carry > 9) { carry = 1; }
            else { carry = 0; }
        }
    }


    string plus(vector<vector<string>>& sum, int totlength, int length2)
    {
        string ans;
        int carry = 0;
        for (int i = 0; i < totlength; ++i)
        {
            int tot = 0;
            for (int j = 0; j < length2; ++j)
            {
                cout << sum[j][i] << endl;
                tot += (sum[j][i] == "" ? 0 : stoi(sum[j][i]));
            }
            cout << ans << " " << carry;
            ans += to_string((tot + carry) % 10);
            carry = (tot + carry) / 10;
        }
        if (carry != 0)
        {
        ans += to_string(carry);
        }
        return ans;
    }

    string multiply(string num1, string num2) {
        vector<vector<string>> sum(50, vector<string>(50, ""));
        string ans;
        int totLength = num1.length() + num2.length();
        for (int i = num2.length() - 1; i > -1; --i)
        {
            mul(num1, num2[i] - '0', sum, i);
        }
        return plus(sum, totLength, num2.length());
    }

    int main()
    {
        string num1 = "123", num2 = "123";
        cout << multiply(num1, num2);
        return 0;
    }
};