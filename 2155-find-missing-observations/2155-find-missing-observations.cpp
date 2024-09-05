class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        // Calculate total sum that the n + m rolls should add up to
        int total_sum = mean * (n + m);
        
        // Calculate the sum of the given rolls
        int given_sum = 0;
        for (int roll : rolls) {
            given_sum += roll;
        }
        
        // Calculate the sum of the missing rolls
        int missing_sum = total_sum - given_sum;
        
        // Check if the missing sum is valid
        if (missing_sum < n || missing_sum > 6 * n) {
            return {}; // It's impossible to distribute the missing sum among n rolls
        }
        
        // Initialize the result array with n elements
        vector<int> result(n, 1);
        
        // Distribute the remaining missing sum
        missing_sum -= n;  // We've already assigned 1 to each roll
        
        // Distribute the remaining sum as evenly as possible
        for (int i = 0; i < n && missing_sum > 0; ++i) {
            int add = min(5, missing_sum);  // We can add at most 5 to each roll
            result[i] += add;
            missing_sum -= add;
        }
        
        return result;
    }
};
