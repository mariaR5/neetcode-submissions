class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        string str = "";
        int maxlen = INT_MIN;
        int i = 0, j = i;

        while (j < s.size()) {
            char ch = s[j];

            if (str.find(ch) == string::npos) {
                str += ch;
                maxlen = max((int)str.size(), maxlen);
                j++;
            }
            else {
                maxlen = max((int)str.size(), maxlen); 
                while (i < s.size() && s[i] != ch) {
                    str.erase(str.begin());
                    i++;
                }
                str.erase(str.begin());
                i++;
            }
        } 
        
        return maxlen;
    }
};
