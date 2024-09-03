#include <vector>

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        // Step 1: Calculate total chalk consumption in one full round
        long long total_chalk = 0;
        for (int c : chalk) {
            total_chalk += c;
        }
        
        // Step 2: Reduce k by the total chalk consumption
        k %= total_chalk;
        
        // Step 3: Find the student who cannot complete their problem
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        // This return should never be reached due to problem constraints
        return -1;
    }
};
