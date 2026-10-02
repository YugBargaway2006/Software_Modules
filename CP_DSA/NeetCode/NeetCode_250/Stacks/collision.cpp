class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto x : asteroids) {
            if(st.empty()) st.push(x);
            else if(x > 0) {
                st.push(x);
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(x)) {
                    st.pop();
                }
                if(st.empty()) st.push(x);
                else if(st.top() < 0) st.push(x);
                else if(st.top() == abs(x)) {
                    st.pop();
                }
            }
        }

        vector<int> res;
        while(!st.empty()) {
            auto u = st.top(); st.pop();
            res.push_back(u);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};