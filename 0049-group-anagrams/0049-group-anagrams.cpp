class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         // Hash map to store the groups of anagrams
        unordered_map<string, vector<string>> anagramGroups;
        
        // Process each string
        for (const string& str : strs) {
            // Create a copy of the string and sort it
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            
            // Use the sorted string as a key to group anagrams
            anagramGroups[sortedStr].push_back(str);
        }
        
        // Prepare the result from the hash map
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};