class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string str: strs) {
            for (char ch: str) {
                encoded += ch + 3;
            }
            encoded += '\n';
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string str = "";

        for(char ch: s) {
            if (ch != '\n') 
                str += ch - 3;
            else {
                decoded.push_back(str);
                str = "";
            }
        }

        return decoded;
    }
};
