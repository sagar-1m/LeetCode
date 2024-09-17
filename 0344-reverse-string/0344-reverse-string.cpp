#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        // Continue swapping while left is less than right
        while (left < right) {
            // Swap the characters at left and right
            swap(s[left], s[right]);
            // Move the pointers towards the center
            left++;
            right--;
        }
    }
};
