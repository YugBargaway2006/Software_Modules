class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int v = st.top(); st.pop();
                int u = st.top(); st.pop();

                if (s == "+") st.push(u + v);
                else if (s == "-") st.push(u - v);
                else if (s == "*") st.push(u * v);
                else st.push(u / v);
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};