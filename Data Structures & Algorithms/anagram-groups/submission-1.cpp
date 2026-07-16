class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;

        for(string str: strs) {
            vector<int> arr(26, 0);
            for (char c: str) {
               arr[c - 'a']++;
            }

            string key;
            for (int x: arr) {
                key += to_string(x);
                key += '#';
            }

            mpp[key].push_back(str);                       
        }
        for (auto k: mpp) {
            result.push_back(k.second);
        }
        return result;
    }
};
