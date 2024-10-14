#include <queue>
#include <vector>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Priority queue (max heap) to store the numbers (negative for max-heap behavior)
        std::priority_queue<long long> maxHeap;
        
        // Push all elements into the max heap
        for (int num : nums) {
            maxHeap.push(num);
        }
        
        long long score = 0;
        
        // Perform k operations
        for (int i = 0; i < k; ++i) {
            // Get the largest element (from the top of the max heap)
            long long largest = maxHeap.top();
            maxHeap.pop();
            
            // Add the largest element to the score
            score += largest;
            
            // Replace the largest element with ceil(largest / 3)
            long long new_value = (largest + 2) / 3;
            
            // Push the new value back into the heap
            maxHeap.push(new_value);
        }
        
        return score;
    }
};
