#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    stack<long long> sum;
    stack<char> opp;
    for (int i = 0; i < n; ++i)
    {
        int curn; char curc;
        cin >> curn;
        sum.push(curn);
        for (int j = 0; j < 2; ++j)
        {
            cin >> curc;
            cin >> curn;
            if (curc == '*')
            {
                long long curs = (long long)sum.top() * curn;
                sum.pop();
                sum.push(curs);
            }
            else
            {
                sum.push(curn);
                opp.push(curc);
            }
        }
        while(!opp.empty())
        {
            long long num1 = sum.top();sum.pop();
            long long num2 = sum.top();sum.pop();
            char op = opp.top();opp.pop();
            if (op == '+')
            {
                long long cursum = (long long)num1+num2;
                sum.push(cursum);
            }
            else
            {
                long long cursum = -num1+num2;
                sum.push(cursum);
            }
        }
        cout << sum.top() << endl;
        sum.pop();
        getchar();
    }
}