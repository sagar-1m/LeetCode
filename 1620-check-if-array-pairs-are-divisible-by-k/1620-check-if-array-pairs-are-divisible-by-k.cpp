#include <vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder_count(k, 0);
        
        // Calculate remainder frequencies
        for (int num : arr) {
            int rem = ((num % k) + k) % k; // Handle negative numbers
            remainder_count[rem]++;
        }
        
        // Check pairs for remainders
        if (remainder_count[0] % 2 != 0) {
            // If there are an odd number of elements with remainder 0, return false
            return false;
        }
        
        for (int i = 1; i <= k / 2; ++i) {
            if (remainder_count[i] != remainder_count[k - i]) {
                return false; // Pair counts do not match
            }
        }
        
        // If we pass all checks, return true
        return true;
    }
};
