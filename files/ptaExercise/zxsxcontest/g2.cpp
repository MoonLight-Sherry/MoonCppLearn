#include <iostream>
#include <string>

using namespace std;
long long det(int n, int **mat);

int main()
{
    int n;
    cin >> n;
    getchar();
    int **a = new int *[n];

    for (int z = 0; z < n; ++z)
    {
        a[z] = new int[n];
    }
    long long result = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    cout << det(n, a);
}

long long det(int n, int **mat)
{
    int mov = 0;
    int flag;
    long long sum = 0;
    if (n == 1)
        return mat[0][0];
    int **b = new int *[n - 1];
    for (int z = 0; z < n - 1; ++z)
        b[z] = new int[n - 1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            mov = i > j ? 0 : 1;
            for (int k = 0; k < n - 1; ++k)
                b[j][k] = mat[j + mov][k + 1];
            if (i % 2 == 0)
                flag = 1;
            else
                flag = -1;
            sum += flag * mat[i][0] * det(n - 1, b);
        }
        delete[] b;
        return sum;
    }
}