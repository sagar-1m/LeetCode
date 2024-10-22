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
    long long kthLargestLevelSum(TreeNode* root, int k) {
         if (!root) return -1; // Edge case if the root is null

        vector<long long> levelSums; // Vector to store level sums
        queue<TreeNode*> q; // Queue for level order traversal
        q.push(root);

        while (!q.empty()) {
            long long levelSum = 0; // Variable to hold the sum of the current level
            int levelSize = q.size(); // Number of nodes at the current level

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val; // Add node value to the level sum
                
                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            levelSums.push_back(levelSum); // Store the sum of the current level
        }

        // Sort the level sums in descending order
        sort(levelSums.rbegin(), levelSums.rend());

        // Check if k is within the bounds of level sums
        if (k > levelSums.size()) return -1;
        
        return levelSums[k - 1]; // Return the kth largest level sum
    }
};