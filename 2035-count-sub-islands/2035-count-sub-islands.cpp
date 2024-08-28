class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool& isSubIsland) {
        int m = grid1.size();
        int n = grid1[0].size();
        
        // Boundary check and if the cell is water or already visited, return
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0) {
            return;
        }
        
        // If this part of the island in grid2 is not in grid1, it's not a sub-island
        if (grid1[i][j] == 0) {
            isSubIsland = false;
        }
        
        // Mark the cell as visited
        grid2[i][j] = 0;
        
        // Explore all 4 directions
        dfs(grid1, grid2, i + 1, j, isSubIsland);
        dfs(grid1, grid2, i - 1, j, isSubIsland);
        dfs(grid1, grid2, i, j + 1, isSubIsland);
        dfs(grid1, grid2, i, j - 1, isSubIsland);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int subIslandCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    bool isSubIsland = true;
                    dfs(grid1, grid2, i, j, isSubIsland);
                    if (isSubIsland) {
                        ++subIslandCount;
                    }
                }
            }
        }
        
        return subIslandCount;
    }
};
