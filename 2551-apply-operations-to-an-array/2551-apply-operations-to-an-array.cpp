class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        vector<int> result;
        
        // Add all non-zero elements to the result
        for (int num : nums) {
            if (num != 0) {
                result.push_back(num);
            }
        }
        
        // Fill the rest with zeros
        while (result.size() < n) {
            result.push_back(0);
        }
        
        return result;
    }
};
