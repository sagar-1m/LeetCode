/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false; // Empty list or a single node with no cycle
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next; // Start fast one step ahead
        
        while (slow != fast) {
            if (!fast || !fast->next) {
                return false; // fast reached the end, no cycle
            }
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;    // Move fast by 2 steps
        }
        
        return true; // slow and fast met, cycle detected
    }
};
