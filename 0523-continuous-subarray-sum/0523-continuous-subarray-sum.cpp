#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mod_map; // To store first occurrence of each modulus
        mod_map[0] = -1; // Handle case where cumulative sum itself is a multiple of k
        int cumulative_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cumulative_sum += nums[i];

            // If k is not zero, take modulus
            if (k != 0) {
                cumulative_sum %= k;
            }

            // Check if this modulus has been seen before
            if (mod_map.count(cumulative_sum)) {
                // Ensure that the length of the subarray is at least 2
                if (i - mod_map[cumulative_sum] > 1) {
                    return true;
                }
            } else {
                // Store the first occurrence of this modulus
                mod_map[cumulative_sum] = i;
            }
        }

        return false;
    }
};
