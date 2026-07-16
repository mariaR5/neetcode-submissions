class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        vector<vector<string>> result;

        for(string str: strs) {
            vector<int> arr(26, 0);
            for (char c: str) {
               arr[c - 'a']++;
            }

            mpp[arr].push_back(str);                       
        }
        for (auto k: mpp) {
            result.push_back(k.second);
        }
        return result;
    }
};
