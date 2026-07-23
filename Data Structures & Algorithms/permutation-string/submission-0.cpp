class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        
        for (char ch: s1) freq[ch - 'a']++;

        int window_size = s1.size();
        vector<int> windowFreq(26, 0);
        int left = 0, right = 0;

        while (right < s2.size()) {
            windowFreq[s2[right] - 'a']++;
            if (right - left + 1 < window_size)   
                right++;

            else {
                if (freq == windowFreq) return true;

                windowFreq[s2[left] - 'a']--;
                left++;
                right++;
            }

        }
        return false;
    }
};
