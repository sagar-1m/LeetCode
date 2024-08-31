class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate elements for i
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements for left and right
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    // Move the pointers inward
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left; // Move left pointer to the right to increase sum
                } else {
                    --right; // Move right pointer to the left to decrease sum
                }
            }
        }
        
        return result;
    }
};
