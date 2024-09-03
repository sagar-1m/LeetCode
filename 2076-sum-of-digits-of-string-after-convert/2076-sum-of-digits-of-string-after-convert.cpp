#include <string>
#include <numeric>

class Solution {
public:
    int getLucky(std::string s, int k) {
        // Step 1: Convert the string to its corresponding numeric string
        std::string num_str;
        for (char ch : s) {
            num_str += std::to_string(ch - 'a' + 1);
        }
        
        // Step 2: Sum the digits k times
        int sum = 0;
        for (char ch : num_str) {
            sum += ch - '0';
        }
        
        while (--k > 0) {
            int new_sum = 0;
            while (sum > 0) {
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }
        
        return sum;
    }
};
