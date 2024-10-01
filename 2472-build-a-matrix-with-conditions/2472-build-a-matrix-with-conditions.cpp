#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to perform topological sort, returns empty vector if a cycle is detected
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> indegree(k + 1, 0);  // Array to store indegree of each node
        vector<vector<int>> adj(k + 1);  // Adjacency list
        
        // Building the graph
        for (const auto& condition : conditions) {
            int u = condition[0];
            int v = condition[1];
            adj[u].push_back(v);  // u -> v means u must come before v
            indegree[v]++;  // Increment indegree of v
        }
        
        // Topological sorting using Kahn's algorithm (BFS)
        queue<int> q;
        vector<int> topoOrder;
        
        // Push all nodes with indegree 0 (nodes with no dependencies)
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            // Process all neighbors
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;  // Remove the edge
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If topological sorting is possible, the size of the result should be k
        if (topoOrder.size() == k) {
            return topoOrder;
        } else {
            return {};  // Cycle detected or incomplete topological sort
        }
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Get topological orders for rows and columns
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        
        // If either topological sorting failed, return empty matrix
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }
        
        // Create the final k x k matrix filled with 0
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        
        // Mapping number -> position for both rows and columns
        unordered_map<int, int> rowPosition;
        unordered_map<int, int> colPosition;
        
        // Assign positions in row and column based on the topological order
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;  // rowOrder[i] should be placed at row i
            colPosition[colOrder[i]] = i;  // colOrder[i] should be placed at col i
        }
        
        // Place the numbers from 1 to k in the matrix based on the computed positions
        for (int num = 1; num <= k; ++num) {
            int r = rowPosition[num];
            int c = colPosition[num];
            matrix[r][c] = num;
        }
        
        return matrix;
    }
};
