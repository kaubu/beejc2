#include <stdlib.h>
#include <stdio.h>

struct iMap {
    int iOne;
    int iTwo;
} iMap;

// returning array must be malloc'd
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *finalArray = malloc(sizeof(returnSize));

    for (int i = 0; i < numsSize; i++) {
        int solution = target - nums[i];

        for (int j = 0; j < numsSize; j++) {
            if (j == solution) {
                // printf("[%d, %d]", i, j);
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
    printf("Expected: [%d,%d]\nResult: [%d,%d]\n----\n", 0, 1, aOne[0], aOne[1]);

    int arrayTwo[] = {3, 2, 4};
    int *aTwo = twoSum(arrayTwo, 3, 6, result);
    printf("Expected: [%d,%d]\nResult: [%d,%d]\n----\n", 1, 2, aTwo[0], aTwo[1]);

    int arrayThree[] = {3, 3};
    int *aThree = twoSum(arrayThree, 2, 6, result);
    printf("Expected: [%d,%d]\nResult: [%d,%d]\n----\n", 0, 1, aThree[0], aThree[1]);
}
