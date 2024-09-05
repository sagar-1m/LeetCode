class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;  // To store the count of each element
        unordered_set<int> occurrenceSet;  // To store the frequencies of the counts

        // Count occurrences of each number
        for (int num : arr) {
            countMap[num]++;
        }

        // Check if the number of occurrences is unique
        for (auto it : countMap) {
            if (occurrenceSet.find(it.second) != occurrenceSet.end()) {
                return false;  // If the frequency is already in the set, return false
            }
            occurrenceSet.insert(it.second);  // Otherwise, add it to the set
        }

        return true;  // If no duplicate frequencies were found, return true
    }
};
