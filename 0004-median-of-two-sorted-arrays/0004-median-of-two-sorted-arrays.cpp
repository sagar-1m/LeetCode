#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            // Ensure nums1 is the smaller array
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int imin = 0, imax = m, half_len = (m + n + 1) / 2;
        
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half_len - i;
            
            if (i < m && nums2[j - 1] > nums1[i]) {
                // i is too small
                imin = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                // i is too big
                imax = i - 1;
            } else {
                // i is perfect
                int max_of_left;
                if (i == 0) {
                    max_of_left = nums2[j - 1];
                } else if (j == 0) {
                    max_of_left = nums1[i - 1];
                } else {
                    max_of_left = std::max(nums1[i - 1], nums2[j - 1]);
                }
                
                if ((m + n) % 2 == 1) {
                    return max_of_left;
                }
                
                int min_of_right;
                if (i == m) {
                    min_of_right = nums2[j];
                } else if (j == n) {
                    min_of_right = nums1[i];
                } else {
                    min_of_right = std::min(nums1[i], nums2[j]);
                }
                
                return (max_of_left + min_of_right) / 2.0;
            }
        }
        
        throw std::invalid_argument("Input arrays are not sorted.");
    }
};
