class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    
    // Resultant vector to store the intersection
    vector<int> result;
    
    // Find common elements by checking in one set
    for (int num : set1) {
        if (set2.count(num)) {
            result.push_back(num);
        }
    }
    
    return result;  
      
    }
};