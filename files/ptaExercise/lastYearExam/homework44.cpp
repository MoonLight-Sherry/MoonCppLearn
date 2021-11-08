#include <stdio.h>

int main()
{
    int m, n;
    char space;
    //int c, r, d;
    scanf("%d%c%d", &m, &space, &n);
    for(int c = 0; c <= m && c <= n/2; ++c)
    {
        for(int r = 0; r <= m - c && r <= (m - c)/4; ++r)
        {
            int d = m - c - r;
            if(2 * c + 4 *r + 6 * d == n)
            {
                printf("%d %d %d\n", c, r, d);
            }
        }
    }
    return 0;
}