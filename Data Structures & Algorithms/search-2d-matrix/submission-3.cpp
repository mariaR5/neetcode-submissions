class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int mid;
        
        int top = 0, bottom = m - 1;
        while (top <= bottom) {
            mid = (top + bottom) / 2;

            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) bottom = mid - 1;
            else top = mid + 1;
        }
        int row = bottom;
        if (row < 0) return false;
        
        int left = 0, right = n - 1;

        while (left <= right) {
            mid = (left + right) / 2;

            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }
};
