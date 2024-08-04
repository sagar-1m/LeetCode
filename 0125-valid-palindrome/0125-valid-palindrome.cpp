class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        // Step 2: Use two pointers to check if the filtered string is a palindrome.
        int left = 0;
        int right = filtered.size() - 1;
        
        while (left < right) {
            if (filtered[left] != filtered[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
        
    }
};