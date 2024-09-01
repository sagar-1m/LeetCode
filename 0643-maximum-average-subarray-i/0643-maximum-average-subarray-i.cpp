class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Initial sum of the first k elements
        double maxSum = 0, currentSum = 0;
        
        for(int i = 0; i < k; i++) {
            currentSum += nums[i];
        }
        
        maxSum = currentSum;
        
        // Sliding window to find the maximum sum
        for(int i = k; i < nums.size(); i++) {
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }
        
        // Return the maximum average
        return maxSum / k;
    }
};
