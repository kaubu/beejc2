#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *finalArray;
    finalArray = malloc(sizeof(returnSize));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == j) continue;

            if ((nums[i] + nums[j]) == target) {
                finalArray[0] = i;
                finalArray[1] = j;
            }
        }
    }

    return finalArray;
}

int main(void)
{
    // Test
    int result[] = {0, 0};
    int arrayOne[] = {2, 7, 11, 15};
    int *aOne = twoSum(arrayOne, 4, 9, result);
    printf("Expected: [%d,%d]\nResult: [%d,%d]", 0, 1, aOne[0], aOne[1]);
}
