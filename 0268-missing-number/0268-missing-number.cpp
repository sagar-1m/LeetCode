class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
        int expectedSum = n * (n + 1) / 2;  // Sum of numbers from 0 to n
        int actualSum = 0;
        
        for(int i = 0; i < n; i++) {
            actualSum += nums[i];  // Sum of elements in the array
        }
        
        return expectedSum - actualSum; 
    }
};