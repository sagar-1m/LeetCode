class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int n = nums.size();
        int left = 0, sum = 0;
        int minLength = n + 1;  // Set to a large value
        
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        
        return minLength == n + 1 ? 0 : minLength;
    }
};