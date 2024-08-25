class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1}; // Return 1-based indices
            } else if (sum < target) {
                left++; // Increase the sum by moving the left pointer to the right
            } else {
                right--; // Decrease the sum by moving the right pointer to the left
            }
        }
        
        // Since the problem guarantees one solution, we don't need to return anything else.
        return {};
    }
};