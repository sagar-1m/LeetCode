class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int maxPoints = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> slopeCount;
            int samePoint = 1;
            int localMax = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i] == points[j]) {
                    samePoint++;
                } else {
                    double slope = calculateSlope(points[i], points[j]);
                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
            }
            maxPoints = max(maxPoints, localMax + samePoint);
        }
        return maxPoints;
    }
    
    double calculateSlope(vector<int>& p1, vector<int>& p2) {
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        if (x1 == x2) return numeric_limits<double>::infinity();
        return (double)(y2 - y1) / (x2 - x1);
    }
};