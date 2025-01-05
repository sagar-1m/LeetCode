class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // Difference array of size n+1
        
        // Step 1: Populate the difference array based on shifts
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int delta = (direction == 1) ? 1 : -1;
            diff[start] += delta;
            if (end + 1 < n) diff[end + 1] -= delta;
        }
        
        // Step 2: Compute the prefix sum to get net shifts
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += diff[i];
            // Step 3: Apply the shift to each character
            int shiftAmount = (netShift % 26 + 26) % 26; // Ensure non-negative shifts
            s[i] = 'a' + (s[i] - 'a' + shiftAmount) % 26;
        }
        
        return s;
    }
};