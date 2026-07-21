class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = INT_MIN;

        while (left < right) {
            int area = (right - left) * min(heights[left], heights[right]);
            
            if (heights[left] < heights[right]) left++;
            else right--;   

            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
