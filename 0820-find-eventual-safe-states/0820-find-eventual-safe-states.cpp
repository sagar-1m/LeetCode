class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n); // 0: unvisited, 1: visiting, 2: safe
        vector<int> safe;

        for (int i = 0; i < n; ++i) 
            if (dfs(graph, i, state)) 
                safe.push_back(i); // Collect safe nodes
        
        return safe;
    }

private:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& state) {
        if (state[node] > 0) return state[node] == 2; // Return true if already safe
        
        state[node] = 1; // Mark as visiting
        
        for (int next : graph[node]) 
            if (state[next] == 1 || !dfs(graph, next, state)) 
                return false; // Cycle detected
        
        state[node] = 2; // Mark as safe
        return true;
    }
};