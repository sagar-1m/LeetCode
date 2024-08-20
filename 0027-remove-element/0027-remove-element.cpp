class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         int k = 0; // Pointer to place the next non-val element
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Place non-val element at the k-th position
                k++; // Increment the position
            }
        }
        
        return k;
    }
};