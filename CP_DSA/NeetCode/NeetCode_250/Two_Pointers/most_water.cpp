class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        int n = heights.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int area = (r-l) * min(heights[l], heights[r]);
            mx = max(area, mx);

            if(heights[l] <= heights[r]) l++;
            else r--;
        }
        return mx;
    }
};
