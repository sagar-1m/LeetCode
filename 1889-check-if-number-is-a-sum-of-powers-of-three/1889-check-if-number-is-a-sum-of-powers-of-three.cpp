class Solution {
public:
    bool checkPowersOfThree(int n) {
     while (n > 0) {
            // Check the least significant digit in base 3
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};