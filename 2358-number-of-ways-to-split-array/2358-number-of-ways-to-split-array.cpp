class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, prefixSum = 0;
        int validSplits = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        // Iterate through the array to calculate prefix sums
        for (int i = 0; i < nums.size() - 1; ++i) { // Only consider indices 0 to n-2
            prefixSum += nums[i];
            if (prefixSum >= totalSum - prefixSum) {
                validSplits++;
            }
        }
        
        return validSplits;
    }
};