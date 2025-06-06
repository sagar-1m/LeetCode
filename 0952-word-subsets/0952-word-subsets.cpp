class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxCount[26] = {0}; // To store the maximum frequency of each character needed

        // Calculate the maximum frequency of each character needed from words2
        for (const auto& word : words2) {
            int count[26] = {0}; // Frequency count for the current word in words2
            for (char ch : word) {
                count[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCount[i] = std::max(maxCount[i], count[i]);
            }
        }

        std::vector<std::string> result; // To store the universal words

        // Check each word in words1
        for (const auto& word : words1) {
            int count[26] = {0}; // Frequency count for the current word in words1
            for (char ch : word) {
                count[ch - 'a']++;
            }

            // Check if this word can cover all character requirements from words2
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (count[i] < maxCount[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};