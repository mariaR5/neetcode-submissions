class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp1, mpp2;

        for(auto i: s) mpp1[i]++;
        for(auto i: t) mpp2[i]++;

        if (mpp1 == mpp2) return true;
        return false;
    }
};
