class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int candidate = nums[0];
        int count = 0;

        // Phase 1: Find the candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;  // Choose new candidate
            }
            count += (num == candidate) ? 1 : -1;
        }

        // No need for Phase 2 to verify the candidate as the problem assumes the majority element always exists.

        return candidate;
    }
};