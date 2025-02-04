class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        int charCount[26] = {0};
        for (char c : s) {
            charCount[c - 'a']++;
        }
        int oddCount = 0;
        for (int i = 0; i < 26; i++) {
            if (charCount[i] % 2 == 1) oddCount++;
        }
        return oddCount <= k;
    }
};