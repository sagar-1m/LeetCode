class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (const int& num : nums) {
            // Check if the number is already in the set
            if (seen.find(num) != seen.end()) {
                return true; // Duplicate found
            }
            // Add the number to the set
            seen.insert(num);
        }
        return false;
    }
};