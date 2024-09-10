class Solution {
public:
    int maxArea(vector<int>& height) {
          int left = 0, right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            // Calculate the area
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth;
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};