class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;  // If the array is empty, return an empty list
        
        int start = nums[0];  // Start of the current range
        
        for (int i = 1; i <= n; ++i) {
            // If we're at the end of the array or the current number isn't consecutive
            if (i == n || nums[i] != nums[i - 1] + 1) {
                // If start equals the previous number, it's a single number range
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Start a new range
                if (i < n) {
                    start = nums[i];
                }
            }
        }
        
        return result;
    }
};
