#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }
    
    int m = matrixSize;
    int n = matrixColSize[0]; // Number of columns
    
    int left = 0;
    int right = (m * n) - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Map the 1D index back to 2D coordinates
        int row = mid / n;
        int col = mid % n;
        int midValue = matrix[row][col];
        
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }
    
    return false; // Target not found
}
