class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 1;
        int l = 0, r = 0;
        long long total = 0;
        
        while (r < n) {
            total += nums[r];
            while ((long long)nums[r] * (r - l + 1) > total + k) {
                total -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        
        return res;   
    }
};