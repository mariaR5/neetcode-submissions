class Solution {
public:
    bool isOperator(string token) {
        if (
            token == "+" ||
            token == "-" ||
            token == "*" ||
            token == "/"
            ) return true;
        return false;
    }
    int operate(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token: tokens) {
            if (isOperator(token)) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(operate(b, a, token));
            }
            else
                st.push(stoi(token));
        }
        return st.top();
    }
};
