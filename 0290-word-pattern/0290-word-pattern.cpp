#include <unordered_map>
#include <sstream>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split the string s into words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // If the number of words and the pattern length are different, return false
        if (words.size() != pattern.size()) {
            return false;
        }

        // Two maps to keep track of the bijection
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check if the pattern character is already mapped to a different word
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }

            // Check if the word is already mapped to a different pattern character
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }

            // Establish the mapping
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};
