class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int count = 0;
        int longest = INT_MIN;

        for(int num: st) {
            if (st.find(num - 1) != st.end()) continue;

            int target = num + 1, count = 1;
            while (st.find(target) != st.end()) {
                target++;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
