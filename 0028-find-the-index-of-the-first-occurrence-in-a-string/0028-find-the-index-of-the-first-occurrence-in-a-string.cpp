class Solution {
public:
    int strStr(string haystack, string needle) {
         if (needle.empty()) return 0;
        
        vector<int> lps(needle.size(), 0);
        int j = 0;
        for (int i = 1; i < needle.size(); i++) {
            while (j > 0 && needle[i] != needle[j]) j = lps[j - 1];
            if (needle[i] == needle[j]) j++;
            lps[i] = j;
        }
        
        j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) j = lps[j - 1];
            if (haystack[i] == needle[j]) j++;
            if (j == needle.size()) return i - needle.size() + 1;
        }
        
        return -1;
    }
};