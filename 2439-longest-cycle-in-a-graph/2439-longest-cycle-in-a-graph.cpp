class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, -1);  // Keeps track of the visit state
        int longest = -1;  // Stores the length of the longest cycle

        // Function to perform DFS and detect cycle lengths
        auto dfs = [&](int start) {
            int depth = 0;
            int cur = start;
            unordered_map<int, int> depthMap;  // To track depth during this traversal
            
            // Traverse the graph following the edges
            while (cur != -1) {
                // If this node was already visited
                if (visited[cur] != -1) {
                    // If the node was visited during this path
                    if (depthMap.find(cur) != depthMap.end()) {
                        // Return the cycle length
                        return depth - depthMap[cur];
                    }
                    return -1;  // No cycle here
                }

                // Mark this node as visited with the current depth
                depthMap[cur] = depth;
                visited[cur] = 1;  // Mark node as visited globally
                depth++;
                cur = edges[cur];  // Move to the next node in the chain
            }

            return -1;  // No cycle found
        };

        // Main loop over all nodes
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {  // Only explore if the node is unvisited
                int cycleLength = dfs(i);  // Perform DFS from this node
                if (cycleLength > longest) {
                    longest = cycleLength;  // Update the longest cycle length
                }
            }
        }

        return longest;
    }
};
