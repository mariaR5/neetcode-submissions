class MinStack {
    stack<pair<int, int>> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) st.push({val, val});
        else {
            int curMin = min(val, st.top().second);
            st.push({val, curMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
