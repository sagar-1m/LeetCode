class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Helper function to find the greatest common divisor (GCD) of two integers
        auto gcd = [](int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };
        
        // Check if str1 + str2 == str2 + str1
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Find the GCD of the lengths of str1 and str2
        int gcdLength = gcd(str1.size(), str2.size());
        
        // The GCD string will be the prefix of str1 with length equal to the GCD of their lengths
        return str1.substr(0, gcdLength);
    }
};
