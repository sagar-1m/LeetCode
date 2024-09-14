class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A number n is a power of two if it is positive and n & (n - 1) == 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};
