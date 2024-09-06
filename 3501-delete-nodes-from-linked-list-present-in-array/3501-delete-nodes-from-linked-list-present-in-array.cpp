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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Step 2: Create a dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* current = head;
        
        // Step 3: Traverse the linked list
        while (current) {
            if (numSet.find(current->val) != numSet.end()) {
                // Skip the node if its value is in nums
                prev->next = current->next;
            } else {
                // Move prev to current node
                prev = current;
            }
            // Move to the next node
            current = current->next;
        }
        
        // Step 4: Return the modified list starting from dummy.next
        return dummy.next;
    }
};