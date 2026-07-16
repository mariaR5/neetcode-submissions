class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = t.length();
        if (s.length() > t.length()) n = s.length();

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i = 0; i < n; i++) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};
