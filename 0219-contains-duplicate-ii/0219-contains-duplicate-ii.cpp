class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numIndices; // Map to store the last index of each number
        
        for (int i = 0; i < nums.size(); ++i) {
            if (numIndices.find(nums[i]) != numIndices.end()) {
                // Check if the difference between the indices is <= k
                if (i - numIndices[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the index of the current number
            numIndices[nums[i]] = i;
        }
        
        return false; // No such pair found
    }
};
