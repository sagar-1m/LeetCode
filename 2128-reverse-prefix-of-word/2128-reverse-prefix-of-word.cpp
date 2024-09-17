#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Find the index of the first occurrence of the character `ch`
        int index = word.find(ch);
        
        // If `ch` is found, apply the two-pointer technique to reverse
        if (index != string::npos) {
            int left = 0;
            int right = index;
            
            // Two-pointer technique to reverse the prefix
            while (left < right) {
                swap(word[left], word[right]);  // Swap characters at the left and right pointers
                left++;
                right--;
            }
        }
        
        // Return the modified or unmodified string
        return word;
    }
};
