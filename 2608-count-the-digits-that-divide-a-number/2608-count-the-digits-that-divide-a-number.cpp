class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        for (int original = num; num > 0; num /= 10) {
            int lastDigit = num % 10;
            if (lastDigit != 0 && original % lastDigit == 0) {
                count++;
            }
        }
        return count;
    }
};
