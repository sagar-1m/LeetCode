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
    // Function to calculate GCD of two numbers
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        
        while (current && current->next) {
            // Calculate the GCD of the current node and the next node
            int gcd_val = gcd(current->val, current->next->val);
            
            // Create a new node with the GCD value
            ListNode* gcd_node = new ListNode(gcd_val);
            
            // Insert the new node between current and next node
            gcd_node->next = current->next;
            current->next = gcd_node;
            
            // Move two steps forward
            current = gcd_node->next;
        }
        
        return head;
    }
};
