class MyQueue {
public:
    stack<int> st, ws;

    MyQueue() {}
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()) {
            auto u = st.top(); st.pop();
            ws.push(u);
        }
        auto ret = ws.top(); ws.pop();
        while(!ws.empty()) {
            auto u = ws.top(); ws.pop();
            st.push(u);
        }
        return ret;
    }
    
    int peek() {
        while(!st.empty()) {
            auto u = st.top(); st.pop();
            ws.push(u);
        }
        auto ret = ws.top();
        while(!ws.empty()) {
            auto u = ws.top(); ws.pop();
            st.push(u);
        }
        return ret;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */