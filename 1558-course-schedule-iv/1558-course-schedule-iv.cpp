class Solution {
public:
    int n;
    bitset<100> path[100]; // Store prerequisite relationships
    vector<int> adj[100];  // Adjacency list for the graph

    void dfs(int start, int i, bitset<100>& visited) {
        visited[i] = 1;     // Mark as visited
        path[start][i] = 1; // path from start to i
        for (int j : adj[i]) {
            if (visited[j]) {
                path[i] |= path[j];
                continue;
            }
            dfs(start, j, visited);
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        this->n = n;

        // Build the graph and initialize prerequisites
        for (auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }

        // Perform DFS from each node
        for (int i = 0; i < n; i++) {
            bitset<100> visited;
            if (!visited[i])
                dfs(i, i, visited); // Start DFS from node i
        }

        const int m = queries.size();
        vector<bool> ans(m, 0);
        for (int i = 0; i < m; i++)
            ans[i] = path[queries[i][0]][queries[i][1]];
        return ans;
    }
};