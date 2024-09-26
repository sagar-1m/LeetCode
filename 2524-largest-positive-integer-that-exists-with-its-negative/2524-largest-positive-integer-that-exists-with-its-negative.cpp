#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());  // Store all elements in a set
        int largestK = -1;  // Initialize the result to -1

        // Iterate through the array and check for each positive number
        for (int num : nums) {
            if (num > 0 && numSet.count(-num)) {
                largestK = max(largestK, num);  // Update largestK if -num exists
            }
        }
        return largestK;
    }
};
