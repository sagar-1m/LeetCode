class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
         int res = 0, min_val = arrays[0][0], max_val = arrays[0].back();
        
        for (int i = 1; i < arrays.size(); i++) {
            res = max(res, max_val - arrays[i][0]);
            res = max(res, arrays[i].back() - min_val);
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }
        
        return res;
    }
};