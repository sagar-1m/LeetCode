class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));  // Initialize n x n matrix with zeros
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;  // Start filling with 1

        while (top <= bottom && left <= right) {
            // Traverse from left to right on the top row
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++;  // Move the top boundary down
            
            // Traverse from top to bottom on the right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--;  // Move the right boundary left
            
            // Traverse from right to left on the bottom row, if valid
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--;  // Move the bottom boundary up
            }
            
            // Traverse from bottom to top on the left column, if valid
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;  // Move the left boundary right
            }
        }
        
        return matrix;
    }
};
