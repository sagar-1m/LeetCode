class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
         sort(nums.begin(), nums.end());

    // Traverse the array from the end, checking triplets
    for (int i = nums.size() - 1; i >= 2; --i) {
        // Check if the triplet forms a valid triangle
        if (nums[i-1] + nums[i-2] > nums[i]) {
            // Return the perimeter if it's valid
            return nums[i] + nums[i-1] + nums[i-2];
        }
    }

    // If no valid triangle was found, return 0
    return 0;
    }
};