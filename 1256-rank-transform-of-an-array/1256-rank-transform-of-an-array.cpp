class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Create a sorted version of the array with unique elements.
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // Use unordered_map to map values to their ranks.
        unordered_map<int, int> rankMap;
        
        // Step 2: Assign ranks to each unique element.
        int rank = 1;
        for (int i = 0; i < sortedArr.size(); ++i) {
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank;
                rank++;
            }
        }
        
        // Step 3: Replace each element in the original array with its rank.
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};
