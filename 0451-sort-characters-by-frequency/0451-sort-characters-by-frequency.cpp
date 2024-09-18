#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freq_map;
        for (char c : s) {
            freq_map[c]++;
        }
        
        // Step 2: Create a vector of pairs (char, frequency) and sort by frequency
        vector<pair<char, int>> freq_vec(freq_map.begin(), freq_map.end());
        sort(freq_vec.begin(), freq_vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return b.second < a.second;  // Sort in decreasing order of frequency
        });
        
        // Step 3: Build the result string based on sorted frequencies
        string result;
        for (auto& p : freq_vec) {
            result.append(p.second, p.first);  // Append the character p.second times
        }
        
        return result;
    }
};
