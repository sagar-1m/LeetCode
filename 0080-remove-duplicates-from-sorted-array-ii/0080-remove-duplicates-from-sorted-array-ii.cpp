class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();  // If the array has 2 or fewer elements, all are valid.
        
        int j = 2;  // Start j at index 2, because the first two elements are always valid.
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[j-2]) {  // Compare current element with the element two positions behind j
                nums[j] = nums[i];  // Place the element at j and increment j
                j++;
            }
        }
        
        return j;  // j is the new length of the array with at most two duplicates
    }
};
