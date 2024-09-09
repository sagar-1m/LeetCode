class Solution {
public:
    string longestPalindrome(string s) {
         if (s.empty()) return "";
        int n = s.length();
        int start = 0, maxLength = 1;  // Keep track of start index and max length of the longest palindrome

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of palindrome found
        };

        // Loop through each character and treat it as the center
        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(i, i);       // Odd length palindrome
            int len2 = expandAroundCenter(i, i + 1);   // Even length palindrome

            int len = max(len1, len2); // Get the maximum length palindrome around the center

            // Update if a longer palindrome is found
            if (len > maxLength) {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }

        return s.substr(start, maxLength);
    }
};