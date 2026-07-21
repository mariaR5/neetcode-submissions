class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i + 1, k = nums.size() - 1;

            int target = -nums[i];

            while (j < k) {
                int sum = nums[j] + nums[k];
                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }

                else if (sum > target) k--;
                else j++;
            }
        }

        return result;
    }
};
