#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build the graph using an adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(b, prob);
            graph[b].emplace_back(u, prob);
        }
        
        // Priority queue to store the (negative probability, node) for max-heap behavior
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        // Track the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        
        // Dijkstra's algorithm for maximum probability path
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            // If we reached the end node, return the probability
            if (node == end_node) return prob;
            
            // Visit neighbors
            for (auto& [neighbor, neighborProb] : graph[node]) {
                double newProb = prob * neighborProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }
        
        // If we exhaust the queue without finding the end node
        return 0.0;
    }
};
