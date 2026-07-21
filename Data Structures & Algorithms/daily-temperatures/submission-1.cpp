class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(i);
                result.push_back(0);
            }
            else {
                while (!st.empty() && temperatures[i] >= temperatures[st.top()] ) {
                    st.pop();
                }
                if (!st.empty()) result.push_back(st.top() - i);
                else result.push_back(0);
                st.push(i);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
