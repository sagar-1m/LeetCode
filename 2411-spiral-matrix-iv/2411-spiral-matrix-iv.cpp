/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Step 2: Initialize the boundaries
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        // Step 3: Traverse the linked list
        ListNode* current = head;
        
        // Step 4: Fill the matrix in spiral order
        while (current && top <= bottom && left <= right) {
            // Fill top row (left to right)
            for (int i = left; i <= right && current; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            ++top;  // Move top boundary down
            
            // Fill right column (top to bottom)
            for (int i = top; i <= bottom && current; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            --right;  // Move right boundary left
            
            // Fill bottom row (right to left)
            for (int i = right; i >= left && current; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            --bottom;  // Move bottom boundary up
            
            // Fill left column (bottom to top)
            for (int i = bottom; i >= top && current; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            ++left;  // Move left boundary right
        }
        
        // Step 5: Return the matrix
        return matrix;
    }
};