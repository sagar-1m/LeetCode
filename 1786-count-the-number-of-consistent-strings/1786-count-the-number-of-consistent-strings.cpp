class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set of allowed characters
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        
        int count = 0;
        
        // Check each word in the words array
        for (const string& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    isConsistent = false;
                    break; // No need to check further characters
                }
            }
            if (isConsistent) {
                count++;
            }
        }
        
        return count;
    }
};
