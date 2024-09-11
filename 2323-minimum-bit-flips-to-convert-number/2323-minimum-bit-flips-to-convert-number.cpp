class Solution {
public:
    int minBitFlips(int start, int goal) {
         int xorResult = start ^ goal;
        
        // Count the number of 1s in the XOR result
        int count = 0;
        while (xorResult > 0) {
            count += xorResult & 1;  // Check if the last bit is 1
            xorResult >>= 1;         // Right shift to check the next bit
        }
        
        return count;
    }
};