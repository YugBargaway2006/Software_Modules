class MinStack {
public:
    stack<int> st, pre;

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(pre.empty()) pre.push(val); 
        else pre.push(min(val, pre.top()));
    }
    
    void pop() {
        st.pop(); pre.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return pre.top();
    }
};
