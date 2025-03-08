class Solution {
public:
    int minimumRecolors(string blocks, int k) {
         int n = blocks.size();
        int min_operations = k; // Maximum possible operations is to recolor all 'k' blocks

        for (int i = 0; i <= n - k; ++i) {
            int count_w = 0;
            for (int j = i; j < i + k; ++j) {
                if (blocks[j] == 'W') {
                    ++count_w;
                }
            }
            min_operations = min(min_operations, count_w);
        }

        return min_operations;
    }
};