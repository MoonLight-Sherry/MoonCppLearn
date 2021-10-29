#include <stdio.h>


int main()
{
    char cur;
    int count = 0;
    char nums[20];
    while((cur = getchar()) != '\n')
    {
        count ++;
        nums[count] = cur - '0';
    }
    if(nums[count] == 0){printf("The number cannot be changed."); return 0;}
    for(int i = 0; i <= count/2; ++i)
    {
          int temp = nums[i];
          nums[i] = nums[count - i];
          nums[count - i] = temp;
    }
    for(int i = 0; i <= count; ++i)
    {
        printf("%d",nums[i]);
    }
    printf("\n");
    return 0;
    
}