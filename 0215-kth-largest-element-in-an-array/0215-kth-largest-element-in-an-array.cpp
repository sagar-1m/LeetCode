#include <cstdlib>  // for rand()

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int quickselect(vector<int>& nums, int left, int right, int k_smallest) {
        if (left == right) { 
            return nums[left];
        }

        // Select a random pivot index between left and right
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);

        if (k_smallest == pivotIndex) {
            return nums[k_smallest];
        } else if (k_smallest < pivotIndex) {
            return quickselect(nums, left, pivotIndex - 1, k_smallest);
        } else {
            return quickselect(nums, pivotIndex + 1, right, k_smallest);
        }
    }
    
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivot = nums[pivotIndex];
        // Move pivot to the end
        swap(nums[pivotIndex], nums[right]);
        int storeIndex = left;

        // Move all smaller elements to the left
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        // Move pivot to its final place
        swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
};
