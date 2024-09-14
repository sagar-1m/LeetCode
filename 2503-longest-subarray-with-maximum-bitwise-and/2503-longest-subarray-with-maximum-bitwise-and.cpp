class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Step 1: Find the maximum value in the array
        int max_value = *max_element(nums.begin(), nums.end());
        
        // Step 2: Find the longest subarray where all elements are equal to max_value
        int longest = 0;
        int current_length = 0;
        
        for (int num : nums) {
            if (num == max_value) {
                // If the current number is the max value, increment the current streak
                current_length++;
                longest = max(longest, current_length);
            } else {
                // Reset the current streak if the number isn't equal to the max value
                current_length = 0;
            }
        }
        
        return longest;
    }
};
