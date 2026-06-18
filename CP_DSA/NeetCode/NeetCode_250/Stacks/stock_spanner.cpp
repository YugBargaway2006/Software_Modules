class StockSpanner {
public:
    vector<int> stocks;
    stack<int> st;
    int idx = -1;

    StockSpanner() {}
    
    int next(int price) {
        stocks.push_back(price);
        idx += 1;

        while(!st.empty() && stocks[st.top()] <= price) {
            st.pop();
        }
        if(st.empty()) {
            st.push(idx);
            return idx+1;
        } else {
            auto u = st.top();
            st.push(idx);
            return idx - u;
        } 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */