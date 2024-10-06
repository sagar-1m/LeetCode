class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        
        // If s1 is longer than s2, no permutation of s1 can be a substring of s2
        if (n1 > n2) return false;
        
        // Frequency arrays to hold the count of each character (for 'a' to 'z')
        vector<int> s1_count(26, 0), s2_count(26, 0);
        
        // Count the frequency of characters in s1 and the first window of s2
        for (int i = 0; i < n1; ++i) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        
        // Now, use the sliding window approach
        for (int i = n1; i < n2; ++i) {
            // If the character frequencies match, return true
            if (s1_count == s2_count) return true;
            
            // Slide the window: add the new character in the window
            s2_count[s2[i] - 'a']++;
            
            // Remove the old character (leftmost) from the window
            s2_count[s2[i - n1] - 'a']--;
        }
        
        // Check for the last window
        return s1_count == s2_count;
    }
};
