class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the total number of nodes in the linked list
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        
        // Step 2: Determine the size of each part and the remainder
        int baseSize = n / k; // minimum number of nodes in each part
        int remainder = n % k; // extra nodes to distribute
        
        vector<ListNode*> result(k, nullptr); // this will store the k parts
        ListNode* current = head;
        
        for (int i = 0; i < k; i++) {
            if (current == nullptr) {
                result[i] = nullptr; // if no more nodes are left, fill with null
                continue;
            }
            
            // Step 3: Determine the size of the current part
            int currentPartSize = baseSize + (remainder > 0 ? 1 : 0); // distribute one extra node if remainder > 0
            remainder--; // reduce the remainder
            
            // Step 4: Create the current part
            result[i] = current; // start the current part
            ListNode* prev = nullptr;
            for (int j = 0; j < currentPartSize; j++) {
                prev = current;
                current = current->next;
            }
            
            // Break the link to the next part
            if (prev != nullptr) {
                prev->next = nullptr;
            }
        }
        
        return result;
    }
};
