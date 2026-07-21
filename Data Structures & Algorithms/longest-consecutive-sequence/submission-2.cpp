class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> mpp;
        int count = 0;
        int longest = INT_MIN;

        for(int num: nums) mpp[num]++;

        for(int num: nums) {
            if (mpp.find(num - 1) != mpp.end()) continue;

            int target = num + 1, count = 0;
            while (mpp.find(target) != mpp.end()) {
                target++;
                count++;
            }
            count++;

            longest = max(longest, count);
        }

        return longest;
    }
};
