#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSumAbsoluteDifferences(int* nums, const int numsSize, int* returnSize){
    int sum = 0;
    int preSum[numsSize];
    *returnSize = numsSize;
    int *result = (int *)malloc(sizeof(int) * *returnSize);
    memset(result, 0, sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
        preSum[i] = sum;
    }
    
    for (int i = 0; i < numsSize; ++i)
    {
        result[i] = -preSum[i] + nums[i] * (i + 1) + preSum[numsSize - 1] - preSum[i] - (numsSize - 1 - i) * nums[i];
    }
    return result;
}