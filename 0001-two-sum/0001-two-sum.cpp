class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> seen;
      for (int i = 0; i < nums.size(); i++) {
        int moreNeeded = target - nums[i];
        if (seen.find(moreNeeded) != seen.end()) {
            return {seen[moreNeeded], i};
            }
            seen[nums[i]] = i;
            }
            return {};
    }
};