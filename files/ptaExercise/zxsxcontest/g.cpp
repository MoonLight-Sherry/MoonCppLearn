#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    long long a[n+1][n+1];
    long long result = 0;
    int j0, j1, j2, j3, j4, inverse, flag;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (j0 = 0; j0 < n; ++j0)
    {
        inverse = 0;
        for (j1 = 0; j1 < n; ++j1)
        {
            if (j1 == j0)
                continue;
            else if (j1 < j0)
                ++inverse;
            for (j2 = 0; j2 < n; ++j2)
            {
                if (j2 == j0 || j2 == j1)
                    continue;
                inverse += (j2 < j0) + (j2 < j1);
                for (j3 = 0; j3 < n; ++j3)
                {
                    if (j3 == j2 || j3 == j1 || j3 == j0)
                        continue;
                    inverse += (j3 < j2) + (j3 < j1) + (j3 < j0);
                    for (j4 = 0; j4 < n; ++j4)
                        if (j4 == j3 || j4 == j2 || j4 == j1 || j4 == j0)
                            continue;
                    inverse += (j4 < j3) + (j4 < j2) + (j4 < j1) + (j4 < j0);

                    flag = (inverse % 2 == 0 ? 1 : -1);
                    long long mid = flag;
                    for (int k1 = 0; k1 < n; ++k1)
                    {
                    //     mid *= a[k1][];
                    }
                    result += flag * a[0][j0] * a[1][j1] * a[2][j2] * a[3][j3] * a[4][j4];
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
