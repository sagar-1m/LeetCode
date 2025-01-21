class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
         int n = grid[0].size();
        // Calculate the prefix sums for row 0 and row 1
        vector<long long> prefixTop(n + 1, 0), prefixBottom(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixTop[i + 1] = prefixTop[i] + grid[0][i];
            prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
        }
        
        long long result = LLONG_MAX; // Initialize the result to a large value
        
        // Iterate over each column to determine the split point
        for (int i = 0; i < n; ++i) {
            long long pointsTop = prefixTop[n] - prefixTop[i + 1]; // Points left in row 0
            long long pointsBottom = prefixBottom[i];            // Points collected in row 1
            
            // Max points collected by the second robot
            long long secondRobotPoints = max(pointsTop, pointsBottom);
            
            // Minimize the maximum points for the second robot
            result = min(result, secondRobotPoints);
        }
        
        return result;
    }
};