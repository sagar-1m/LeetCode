class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If target is found
            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates: If left == mid == right, we cannot determine which part is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // If the left side is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Search in the left half
                } else {
                    left = mid + 1;  // Search in the right half
                }
            }
            // If the right side is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Search in the right half
                } else {
                    right = mid - 1; // Search in the left half
                }
            }
        }

        // If the loop ends and the target is not found
        return false;
    }
};
