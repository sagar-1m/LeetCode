class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLength = pref.length();

        for (const std::string& word : words) {
            if (word.length() >= prefLength && word.substr(0, prefLength) == pref) {
                count++;
            }
        }

        return count;
    }
};