class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Convert the input arrays to sets
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        // Prepare vectors to store the results
        vector<int> diff1, diff2;
        
        // Find elements in set1 that are not in set2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                diff1.push_back(num);
            }
        }
        
        // Find elements in set2 that are not in set1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                diff2.push_back(num);
            }
        }
        
        // Return the result as a vector of vectors
        return {diff1, diff2};
    }
};
