#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the array of people's weights
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;  // Two pointers
        int boats = 0;  // Count of boats
        
        while (i <= j) {
            // Try to pair the lightest and the heaviest
            if (people[i] + people[j] <= limit) {
                i++;  // Move the lightest pointer if they can be paired
            }
            j--;  // Always move the heaviest pointer
            boats++;  // A boat is used
        }
        
        return boats;
    }
};
