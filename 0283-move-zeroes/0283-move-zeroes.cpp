class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;  // Pointer to track the position of the first zero

        // Traverse the array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                // Swap the current element with the element at index j
                swap(nums[i], nums[j]);
                j++;
            }
        }
    
        
    }
};