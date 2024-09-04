#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions array: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;  // Start facing North
        int x = 0, y = 0;  // Starting position
        
        // Convert obstacle list to a set of strings for quick lookup
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
        
        int maxDistanceSq = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left
                directionIndex = (directionIndex + 3) % 4;
            } else if (command == -1) {
                // Turn right
                directionIndex = (directionIndex + 1) % 4;
            } else {
                // Move forward k units
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[directionIndex].first;
                    int nextY = y + directions[directionIndex].second;
                    
                    // Check if next position is an obstacle
                    if (obstacleSet.find(to_string(nextX) + "," + to_string(nextY)) != obstacleSet.end()) {
                        break;
                    }
                    
                    // Update position
                    x = nextX;
                    y = nextY;
                    
                    // Update max distance squared
                    maxDistanceSq = max(maxDistanceSq, x * x + y * y);
                }
            }
        }
        
        return maxDistanceSq;
    }
};
