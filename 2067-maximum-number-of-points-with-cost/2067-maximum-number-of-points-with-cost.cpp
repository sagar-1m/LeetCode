class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n, 0);
        
        for (int i = 0; i < n; i++) {
            dp[i] = points[0][i];
        }
        
        for (int i = 1; i < m; i++) {
            vector<long long> left(n, 0), right(n, 0);
            left[0] = dp[0];
            right[n-1] = dp[n-1];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j-1] - 1, dp[j]);
            }
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j+1] - 1, dp[j]);
            }
            for (int j = 0; j < n; j++) {
                dp[j] = points[i][j] + max(left[j], right[j]);
            }
        }
        
        long long maxPoints = 0;
        for (int i = 0; i < n; i++) {
            maxPoints = max(maxPoints, dp[i]);
        }
        return maxPoints;
    }
};