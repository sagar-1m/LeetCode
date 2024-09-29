class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int totalCells = rows * cols;
        int steps = 1;  // number of steps to take in each direction
        int r = rStart, c = cStart;
        int dirIdx = 0; // start moving right
        
        result.push_back({r, c});  // start point
        int cellsVisited = 1;
        
        while (cellsVisited < totalCells) {
            // Move in spiral pattern
            for (int i = 0; i < 2; ++i) { // alternate direction after 2 moves
                for (int j = 0; j < steps; ++j) {
                    r += directions[dirIdx][0]; // move in the current direction
                    c += directions[dirIdx][1];
                    
                    // Add to result if it's within the grid bounds
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                        cellsVisited++;
                    }
                }
                // Change direction (right -> down -> left -> up)
                dirIdx = (dirIdx + 1) % 4;
            }
            steps++; // after 2 moves, increase steps
        }
        
        return result;
    }
};
