#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Map each vowel to a bit position
        unordered_map<char, int> vowelMap = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        
        // Map to store the first occurrence of each bitmask state
        unordered_map<int, int> stateIndexMap;
        stateIndexMap[0] = -1; // Initial state where all vowels are even at index -1
        
        int maxLength = 0;
        int state = 0; // Bitmask representing vowel counts
        
        // Traverse the string
        for (int i = 0; i < s.length(); ++i) {
            if (vowelMap.find(s[i]) != vowelMap.end()) {
                // Flip the bit corresponding to the current vowel
                state ^= (1 << vowelMap[s[i]]);
            }
            
            // Check if the current state has been seen before
            if (stateIndexMap.find(state) != stateIndexMap.end()) {
                // Calculate the length of the valid substring
                maxLength = max(maxLength, i - stateIndexMap[state]);
            } else {
                // Store the first occurrence of this state
                stateIndexMap[state] = i;
            }
        }
        
        return maxLength;
    }
};
