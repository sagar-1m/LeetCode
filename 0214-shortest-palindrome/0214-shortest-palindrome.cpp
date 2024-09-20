class Solution {
public:
    string shortestPalindrome(string s) {
        // Helper function to compute the KMP prefix table
        auto computePrefixFunction = [](const string& str) {
            int n = str.size();
            vector<int> lps(n, 0);
            int length = 0;
            int i = 1;
            
            while (i < n) {
                if (str[i] == str[length]) {
                    length++;
                    lps[i] = length;
                    i++;
                } else {
                    if (length != 0) {
                        length = lps[length - 1];
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            return lps;
        };
        
        if (s.empty()) return "";

        // Construct the new string for KMP
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;
        
        // Compute the KMP prefix table
        vector<int> lps = computePrefixFunction(new_s);
        
        // Length of the longest palindromic prefix in original string
        int len = lps.back();
        
        // Append the necessary characters in front of the original string
        string suffix = s.substr(len);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};
