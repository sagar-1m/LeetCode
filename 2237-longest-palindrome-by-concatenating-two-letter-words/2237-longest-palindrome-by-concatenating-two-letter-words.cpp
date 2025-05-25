class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int res = 0;
        bool hasMiddle = false;
        
        for (auto& word : words) {
            count[word]++;
        }
        
        for (auto& [word, freq] : count) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            
            if (word != rev) {
                if (count.find(rev) != count.end()) {
                    int pairs = min(count[word], count[rev]);
                    res += pairs * 4;
                    count[word] -= pairs;
                    count[rev] -= pairs;
                }
            } else {
                // word is like "gg"
                int pairs = freq / 2;
                res += pairs * 4;
                count[word] -= pairs * 2;
                if (count[word] > 0) hasMiddle = true;
            }
        }
        
        if (hasMiddle) res += 2;
        return res;
    }
};
