class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(i); continue;
            }

            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                auto idx = st.top(); st.pop();
                res[idx] = i - idx;
            }
            st.push(i);

            // if(temperatures[st.top()] >= temperatures[i]) {
            //     st.push(i);
            // } else {

            // }
        }
        return res;
    }
};
