#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cow[3000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cow[i]);
    }
    int bed;
    int flag = 1;
    for (int i = n; i < 3000; i++)
    {
        flag = 1;
        int beds[3000];
        memset(beds, 0, 3000 * sizeof(int));
        for (int j = 0; j < n && flag; j++)
        {
            int index = cow[j] % i;
            if (beds[index] == 1)
            {
                flag = 0;
                break;
            }
            else
            {
                beds[index] = 1;
            }
        }
        bed = i;
        if (flag == 1){break;}
    }
    printf("%d\n", bed);
    return 0;
}