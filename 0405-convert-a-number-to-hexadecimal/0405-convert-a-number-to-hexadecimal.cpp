class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        // Hexadecimal digits
        string hexDigits = "0123456789abcdef";
        unsigned int n = num;  // Handle negative numbers by using unsigned int
        string result = "";
        
        // Process the number while it's greater than 0
        while (n > 0) {
            // Get the current hexadecimal digit (remainder when dividing by 16)
            result = hexDigits[n % 16] + result;
            // Right shift the number by dividing by 16
            n /= 16;
        }
        
        return result;
    }
};
