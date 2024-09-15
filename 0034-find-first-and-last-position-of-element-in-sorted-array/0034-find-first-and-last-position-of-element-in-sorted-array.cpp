class Solution {
public:
    int findFirstOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firstOccurrence = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                firstOccurrence = mid;  // potential first occurrence
                right = mid - 1;  // keep looking in the left half
            } else if (nums[mid] < target) {
                left = mid + 1;  // search in the right half
            } else {
                right = mid - 1;  // search in the left half
            }
        }
        
        return firstOccurrence;
    }
    
    int findLastOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int lastOccurrence = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                lastOccurrence = mid;  // potential last occurrence
                left = mid + 1;  // keep looking in the right half
            } else if (nums[mid] < target) {
                left = mid + 1;  // search in the right half
            } else {
                right = mid - 1;  // search in the left half
            }
        }
        
        return lastOccurrence;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find the first and last occurrences using binary search
        int first = findFirstOccurrence(nums, target);
        int last = findLastOccurrence(nums, target);
        
        // If the target doesn't exist in the array
        if (first == -1) {
            return {-1, -1};
        }
        
        return {first, last};
    }
};
