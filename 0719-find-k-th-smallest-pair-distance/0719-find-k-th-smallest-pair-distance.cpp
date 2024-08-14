class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0, j = 0;
            for (int i = 0; i < nums.size(); i++) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) j++;
                cnt += j - i - 1;
            }
            if (cnt < k) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};