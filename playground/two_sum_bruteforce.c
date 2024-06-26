/* 
 * Two sum problem from Leetcode
 * this will be brute force since I don't know a better solution
 */

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
                finalArray[0] = j;
                finalArray[1] = i;
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
    printf("Expected: [%d,%d]\nResult: [%d,%d]\n----", 0, 1, aOne[0], aOne[1]);

    int arrayTwo[] = {3, 2, 4};
    int *aTwo = twoSum(arrayTwo, 3, 6, result);
    printf("Expected: [%d,%d]\nResult: [%d,%d]\n----", 1, 2, aTwo[0], aTwo[1]);

    int arrayThree[] = {3, 3};
    int *aThree = twoSum(arrayThree, 2, 6, result);
    printf("Expected: [%d,%d]\nResult: [%d,%d]", 0, 1, aThree[0], aThree[1]);
}
