#include <stdio.h>

int main()
{
    int nums[5] = {0};
    for (int i = 0; i < 4; ++i)
    {
        char cur = getchar();
        if (cur == 'T')
        {
            nums[i] = 10;
            continue;
        }
        nums[i] = cur - '0';
    }

    if (nums[0] == nums[1])
    {
        if (nums[2] == nums[3])
        {
            if (nums[0] == nums[2])
            {
                printf("A:%d\n", nums[0]);
                return 0;
            }
            else if (nums[0] > nums[2])
            {
                printf("A:%d\n", nums[0]);
                return 0;
            }
            else
            {
                printf("B:%d\n", nums[2]);
                return 0;
            }
        }
        else
        {
            printf("A:%d\n", nums[0]);
            return 0;
        }
    }
    else if (nums[2] == nums[3])
    {
        printf("B:%d\n", nums[2]);
        return 0;
    }
    else
    {
        int sum1 = (nums[0] + nums[1])%10;
        int sum2 = (nums[2] + nums[3])%10;
        if(sum1 == sum2)
        {
            int max= 0, maxnum = nums[0];
            for(int k = 1; k < 4; ++k)
            {
                if(nums[k] > maxnum) 
                {
                    max = k;
                    maxnum = nums[k];
                }
            }
            printf("%c:%d\n", max<2? 'A': 'B', sum1);
        }
        else if(sum1 > sum2)
        {
            printf("A:%d\n", sum1);
        }
        else
        {
            printf("B:%d\n", sum2);
        }
    }
    return 0;
}

//30min