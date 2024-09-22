class Solution {
public:
    int findKthNumber(int n, int k) {
        // Start with prefix '1'
        int curr = 1;
        k--;  // Decrease k since we consider the first number is '1'
        
        while (k > 0) {
            // Calculate the count of numbers between curr and curr+1 in the lexicographical order
            long steps = countSteps(curr, n);
            
            if (steps <= k) {
                // If steps are smaller than k, skip this prefix range
                curr++;
                k -= steps;
            } else {
                // Otherwise, go deeper into the current prefix
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
    
    // Helper function to count how many numbers between curr and curr + 1 fit within the range [1, n]
    long countSteps(long curr, long n) {
        long steps = 0;
        long first = curr;
        long last = curr + 1;
        
        // As long as first is within n, count the numbers between first and last
        while (first <= n) {
            steps += min(n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        
        return steps;
    }
};
