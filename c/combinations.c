#include <stdio.h>
#include <stdlib.h>

int getCombinationsCount(int n, int k) {
    if (k > n / 2) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return (int)res;
}

void backtrack(int start, int n, int k, int* current, int currentSize, 
               int** result, int* returnSize, int* currentColumnSizes) {
    if (currentSize == k) {
        result[*returnSize] = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            result[*returnSize][i] = current[i];
        }
        currentColumnSizes[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = start; i <= n - (k - currentSize) + 1; i++) {
        current[currentSize] = i;
        backtrack(i + 1, n, k, current, currentSize + 1, result, returnSize, currentColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int totalCombinations = getCombinationsCount(n, k);
    *returnSize = 0;
    
    int** result = (int**)malloc(totalCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(totalCombinations * sizeof(int));
    
    int* current = (int*)malloc(k * sizeof(int));
    
    backtrack(1, n, k, current, 0, result, returnSize, *returnColumnSizes);
    
    free(current);
    
    return result;
}
