class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, n);  // Initialize DP array with maximum possible extra characters
        dp[0] = 0;  // No extra characters when there's no substring
        
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        // Traverse each position in the string
        for (int i = 0; i < n; ++i) {
            // If there's no match, move to the next character and treat it as an extra
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            
            // Try to match each dictionary word starting from position i
            for (const string& word : dict) {
                int len = word.size();
                if (i + len <= n && s.substr(i, len) == word) {
                    dp[i + len] = min(dp[i + len], dp[i]);
                }
            }
        }
        
        return dp[n];  // Minimum extra characters at the end of the string
    }
};
