class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < stones.size(); i++) {
            // Check if the stone is in the same row or column and has not been visited yet
            if (!visited[i] && (stones[i][0] == stones[node][0] || stones[i][1] == stones[node][1])) {
                dfs(i, stones, visited);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int numComponents = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numComponents++;
                dfs(i, stones, visited);
            }
        }
        
        // The maximum number of stones that can be removed
        return n - numComponents;
    }
};
