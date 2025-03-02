

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> idValueMap;
        
        // Add values from nums1 to the map
        for (auto& pair : nums1) {
            idValueMap[pair[0]] += pair[1];
        }
        
        // Add values from nums2 to the map
        for (auto& pair : nums2) {
            idValueMap[pair[0]] += pair[1];
        }
        
        // Create the resulting array
        vector<vector<int>> result;
        for (auto& entry : idValueMap) {
            result.push_back({entry.first, entry.second});
        }
        
        return result; 
    }
};