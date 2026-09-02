#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void backtrack(int* nums, int numsSize, int start, int* current, int currentSize, 
               int** result, int* returnSize, int* returnColumnSizes) {
    result[*returnSize] = (int*)malloc(currentSize * sizeof(int));
    for (int i = 0; i < currentSize; i++) {
        result[*returnSize][i] = current[i];
    }
    returnColumnSizes[*returnSize] = currentSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        current[currentSize] = nums[i];
        backtrack(nums, numsSize, i + 1, current, currentSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalSubsets = 1 << numsSize;
    *returnSize = 0;

    int** result = (int**)malloc(totalSubsets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
    int* current = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, current, 0, result, returnSize, *returnColumnSizes);

    free(current);
    return result;
}
