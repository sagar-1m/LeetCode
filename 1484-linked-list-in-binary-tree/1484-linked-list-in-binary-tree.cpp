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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to check if linked list starting from `head` can be matched starting from `root`
    bool dfs(ListNode* head, TreeNode* root) {
        // If we have matched all nodes in the linked list
        if (!head) return true;
        // If we reached the end of the binary tree without fully matching the linked list
        if (!root) return false;
        
        // If the current node of the tree matches the current node of the list
        if (root->val == head->val) {
            // Recursively check left and right subtrees with the next node of the linked list
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }
        
        return false; // Current tree node doesn't match linked list node
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // If we reach the end of the tree without finding a matching path
        if (!root) return false;
        
        // Check if the list starting from `head` matches from the current tree node, or recursively check in the left and right subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
