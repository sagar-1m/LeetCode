class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        int max_len = 0;

        // Insert all prefixes of numbers from arr1 into a hash set
        for (int num : arr1) {
            string str = to_string(num);
            // Add all prefixes of the current number
            for (int i = 1; i <= str.size(); ++i) {
                prefixes.insert(str.substr(0, i)); // Add prefix of length i
            }
        }

        // For each number in arr2, check the longest matching prefix in the set
        for (int num : arr2) {
            string str = to_string(num);
            for (int i = 1; i <= str.size(); ++i) {
                if (prefixes.count(str.substr(0, i))) {
                    max_len = max(max_len, i); // Update max_len if we find a longer prefix
                } else {
                    break; // Stop early if the prefix is not found
                }
            }
        }

        return max_len; // Return the longest common prefix length found
    }
};
