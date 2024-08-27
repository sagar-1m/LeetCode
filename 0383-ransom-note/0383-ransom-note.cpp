#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charCount(26, 0);  // Frequency array for characters 'a' to 'z'

        // Count the occurrences of each character in the magazine
        for (char c : magazine) {
            charCount[c - 'a']++;
        }

        // Check if the ransomNote can be constructed
        for (char c : ransomNote) {
            if (--charCount[c - 'a'] < 0) {
                return false;  // Not enough of character c in magazine
            }
        }

        return true;
    }
};
