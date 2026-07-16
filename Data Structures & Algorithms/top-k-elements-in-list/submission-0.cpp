class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<vector<int>> v(nums.size() + 1);
        unordered_map<int, int> mpp;

        for (auto i: nums) mpp[i]++;

        for (auto it: mpp) {
            v[it.second].push_back(it.first);
        }

        int i = nums.size();
        while(i >= 0 && k > 0) {
            if (!v[i].empty()){
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
