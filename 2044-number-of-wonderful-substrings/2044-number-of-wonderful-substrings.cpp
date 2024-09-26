#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> maskCount;
        maskCount[0] = 1;  // Starting with an empty substring, the bitmask is 0
        int mask = 0;
        long long result = 0;
        
        for (char c : word) {
            // Update the bitmask: toggle the bit corresponding to the current character
            mask ^= (1 << (c - 'a'));
            
            // If we've seen this exact mask before, it means all frequencies between the previous
            // position and the current one are even
            result += maskCount[mask];
            
            // Check all masks that differ by exactly one bit (i.e., only one character has an odd frequency)
            for (int i = 0; i < 10; ++i) {
                int toggledMask = mask ^ (1 << i);
                result += maskCount[toggledMask];
            }
            
            // Increment the count for the current mask
            maskCount[mask]++;
        }
        
        return result;
    }
};
