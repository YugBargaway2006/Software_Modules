class Solution {
public:
    vector<int> nse, pse;

    void calculate(vector<int>& arr, int n) {
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                nse[st.top()] = i;
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        nse.assign(n, n);
        pse.assign(n, -1);

        calculate(heights, n);

        int mx = 0;

        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            mx = max(mx, heights[i] * width);
        }

        return mx;
    }
};