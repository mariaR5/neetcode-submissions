class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int arr[26] = {0};
        for (char ch: s) {
            for (int i = 0; i < 26; i++)
                arr[ch -'a']++;
        }
        for (char ch: t) {
            for (int i = 0; i < 26; i++) arr[ch -'a']--;
        }
         for (int i: arr) {
            if (i != 0) return false;
        }
        return true;
    }
};
