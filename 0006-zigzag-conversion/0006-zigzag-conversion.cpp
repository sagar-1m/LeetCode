class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;  // No zigzagging needed for 1 row
        }
        
        // Create a vector of strings for each row
        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool goingDown = false;
        
        // Traverse the string and place characters in the correct row
        for (char c : s) {
            rows[currRow] += c;  // Append the character to the current row
            
            // If we're at the top or bottom row, we need to reverse direction
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row (down or up)
            currRow += goingDown ? 1 : -1;
        }
        
        // Combine all rows into one string
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};
