#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total_sum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            total_sum = (total_sum + num) % p;
        }
        
        // If the sum is already divisible by p, no need to remove any subarray
        if (total_sum == 0) return 0;
        
        // We want to find a subarray whose sum gives this remainder to remove
        int rem = total_sum;
        
        // Hash map to store the latest prefix sum mod p
        unordered_map<int, int> mod_map;
        mod_map[0] = -1;  // Base case: prefix sum mod p is 0 at index -1
        
        int prefix_sum = 0;
        int min_len = n;
        
        for (int i = 0; i < n; ++i) {
            // Update the current prefix sum
            prefix_sum = (prefix_sum + nums[i]) % p;
            
            // The mod value we are looking for to make the remaining sum divisible by p
            int target_mod = (prefix_sum - rem + p) % p;
            
            // If the target mod exists in the map, we have a valid subarray to remove
            if (mod_map.find(target_mod) != mod_map.end()) {
                int subarray_len = i - mod_map[target_mod];
                min_len = min(min_len, subarray_len);
            }
            
            // Update the map with the current prefix sum mod p
            mod_map[prefix_sum] = i;
        }
        
        // If we didn't find any valid subarray, return -1
        return (min_len == n) ? -1 : min_len;
    }
};
