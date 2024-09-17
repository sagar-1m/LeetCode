#include <string>
#include <cctype>  // For isalpha()

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // If left is not a letter, move it forward
            if (!isalpha(s[left])) {
                left++;
            }
            // If right is not a letter, move it backward
            else if (!isalpha(s[right])) {
                right--;
            }
            // If both are letters, swap them
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
