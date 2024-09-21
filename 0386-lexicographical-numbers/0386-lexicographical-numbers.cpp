class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;

        // Start the DFS from each number 1-9
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, result); // Call DFS
        }

        return result;
    }

private:
    void dfs(int curr, int n, vector<int>& result) {
        if (curr > n) return; // Stop if current number exceeds n
        result.push_back(curr); // Add current number to result
        
        // Generate next numbers by multiplying by 10 and adding digits 0-9
        for (int i = 0; i < 10; ++i) {
            int next = curr * 10 + i;
            if (next > n) break; // No need to go further if next exceeds n
            dfs(next, n, result); // Recursive call to DFS
        }
    }
};
