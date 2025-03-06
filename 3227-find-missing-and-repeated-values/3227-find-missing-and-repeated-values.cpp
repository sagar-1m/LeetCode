class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;
        int expectedSum = n2 * (n2 + 1) / 2; // Sum of first n^2 natural numbers
        int actualSum = 0;
        unordered_set<int> elements;
        int repeated = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                actualSum += grid[i][j];
                if (elements.count(grid[i][j])) {
                    repeated = grid[i][j];
                } else {
                    elements.insert(grid[i][j]);
                }
            }
        }

        int missing = expectedSum - (actualSum - repeated);
        return {repeated, missing};
    }
};