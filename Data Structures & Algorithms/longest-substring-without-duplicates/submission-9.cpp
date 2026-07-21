class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
         unordered_set<int> st;
        int maxlen = INT_MIN;
        int i = 0, j = i;

        while (j < s.size()) {
            char ch = s[j];

            if (st.find(ch) == st.end()) {
                st.insert(ch);
                maxlen = max((j-i+1), maxlen);
                j++;
            }
            else {
                st.erase(s[i]);
                i++;
            }
        } 
        
        return maxlen;
    }
};
