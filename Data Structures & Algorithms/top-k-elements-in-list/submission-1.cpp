class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<vector<int>> v(nums.size() + 1);
        vector<int> result;

        for (int x: nums) mpp[x]++;

        for (auto it: mpp)
            v[it.second].push_back(it.first);

        int i = v.size() - 1;

        while (i >= 0 && k > 0) {
            if (!v[i].empty()) {
                for (int num: v[i]) {
                    result.push_back(num);
                    if (result.size() == k) return result;
                }
            }
            i--;
        }

        return {};
    }
};
