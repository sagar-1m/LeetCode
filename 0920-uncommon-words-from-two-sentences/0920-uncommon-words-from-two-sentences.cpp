#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Combine the sentences into a single string
        string combined = s1 + " " + s2;
        
        // Use a map to count the frequency of each word
        unordered_map<string, int> wordCount;
        
        // Split the combined string into words using stringstream
        stringstream ss(combined);
        string word;
        while (ss >> word) {
            wordCount[word]++;
        }
        
        // Collect the words that appear exactly once
        vector<string> result;
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};
