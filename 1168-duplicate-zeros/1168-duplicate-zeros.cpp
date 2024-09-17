#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        
        // First pass: count the number of zeros to be duplicated
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                zeros++;
            }
        }
        
        // Second pass: fill the array from the end, duplicating zeros
        for (int i = n - 1, j = n + zeros - 1; i >= 0; --i, --j) {
            // If j is within bounds, copy the element from arr[i] to arr[j]
            if (j < n) {
                arr[j] = arr[i];
            }
            // If arr[i] is zero, duplicate it
            if (arr[i] == 0) {
                --j;
                if (j < n) {
                    arr[j] = 0; // Duplicate the zero
                }
            }
        }
    }
};
