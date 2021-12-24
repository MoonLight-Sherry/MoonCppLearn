#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    getchar();
    int mat[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
        getchar();
    }
    if (k >= n)
    {
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += accumulate(&mat[i][0], &mat[i][n -1], 0);
        }
        cout << sum << endl;
    }
    else 
    {
        long long minsum = 1e6;
        for (int i = 0; i < n - k; ++i)
        {
            long long cursum = 0;
            for (int j = 0; j < n - k; ++j)
            {
                cursum += accumulate(&mat[i][j], &mat[i][j+k - 1], 0);
            }
            minsum = min(cursum, minsum);
        }
        cout << minsum << endl;
    }
    return 0;
}