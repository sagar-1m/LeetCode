class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        // Step 1: Filter the string to remove non-alphanumeric characters and convert to lowercase.
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        
        // Step 2: Use recursive function to check if the filtered string is a palindrome.
        return isPalindromeRecursive(filtered, 0, filtered.size() - 1);
    }

private:
    bool isPalindromeRecursive(const string &s, int left, int right) {
        // Base case: If left pointer is greater than or equal to right pointer, it's a palindrome
        if (left >= right) {
            return true;
        }
        // If characters at current pointers don't match, it's not a palindrome
        if (s[left] != s[right]) {
            return false;
        }
        // Recur for the next set of characters
        return isPalindromeRecursive(s, left + 1, right - 1);
    }
};
