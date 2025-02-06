class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        int count = 0;

        // Store all product pairs in the hash map
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Calculate the number of valid tuples
        for (const auto& [product, freq] : productCount) {
            if (freq > 1) {
                count += 8 * (freq * (freq - 1) / 2);
            }
        }

        return count;
    }
};