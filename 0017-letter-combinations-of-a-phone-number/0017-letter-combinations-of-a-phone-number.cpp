class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        // Map digits to corresponding letters
        vector<string> digitToLetters = {
            "",     // 0 (not used)
            "",     // 1 (not used)
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string currentCombination;
        
        // Start the backtracking process
        backtrack(digits, 0, digitToLetters, currentCombination, result);
        
        return result;
    }
    
private:
    void backtrack(const string &digits, int index, const vector<string> &digitToLetters,
                   string &currentCombination, vector<string> &result) {
        // Base case: if the current combination is of the same length as digits, we have a complete combination
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }
        
        // Get the letters that the current digit maps to
        int digit = digits[index] - '0';
        const string &letters = digitToLetters[digit];
        
        // Loop through all letters that the current digit can represent
        for (char letter : letters) {
            // Add the letter to the current combination
            currentCombination.push_back(letter);
            // Move on to the next digit
            backtrack(digits, index + 1, digitToLetters, currentCombination, result);
            // Backtrack: remove the last added letter and try the next one
            currentCombination.pop_back();
        }
    }
};
