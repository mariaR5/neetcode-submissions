class Solution {
public:
    int findMin(vector<int> &nums) {
        int right = nums.size() - 1;

        while (right > 0 && nums[right] > nums[right-1])
            right--;
        
        return nums[right];
    }
};
