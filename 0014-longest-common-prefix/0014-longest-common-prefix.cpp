class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) {
            return "";
        }
        
        string prefix = "";
        
        for (int i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            
            for (const string& str : strs) {
                if (i >= str.size() || str[i] != ch) {
                    return prefix;
                }
            }
            
            prefix += ch;
        }
        
        return prefix;
    }
};