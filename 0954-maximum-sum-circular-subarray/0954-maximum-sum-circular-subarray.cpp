class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
           int n = nums.size();
        
        // Step 1: Kadane's algorithm for maximum subarray sum (non-circular)
        int max_ending_here = nums[0];
        int max_so_far = nums[0];
        for (int i = 1; i < n; ++i) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        
        // Step 2: Calculate total sum of the array
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        // Step 3: Kadane's algorithm for minimum subarray sum
        int min_ending_here = nums[0];
        int min_so_far = nums[0];
        for (int i = 1; i < n; ++i) {
            min_ending_here = min(nums[i], min_ending_here + nums[i]);
            min_so_far = min(min_so_far, min_ending_here);
        }
        
        // Handle the case when all elements are negative
        if (total_sum == min_so_far) {
            return max_so_far;
        }
        
        // Step 4: Calculate maximum circular subarray sum
        int max_circular_sum = total_sum - min_so_far;
        
        // Step 5: Return the maximum of non-circular and circular max subarray sums
        return max(max_so_far, max_circular_sum);
    }
};