class MyStack {
public:
    queue<int> st, workspace;

    MyStack() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()) {
            auto u = st.front(); st.pop();
            if(st.empty()) {
                while(!workspace.empty()) {
                    auto v = workspace.front(); workspace.pop();
                    st.push(v);
                }
                return u;
            }
            workspace.push(u);
        }
    }
    
    int top() {
        int u = pop();
        st.push(u);
        return u;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */