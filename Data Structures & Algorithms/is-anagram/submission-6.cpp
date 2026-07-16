class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for (char ch: s) {
            for (int i = 0; i < 26; i++) {
                if (i == ch -'a') arr[i]++;
            }
        }
        for (char ch: t) {
            for (int i = 0; i < 26; i++) {
                if (i == ch -'a') arr[i]--;
            }
        }
         for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }
};
