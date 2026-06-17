class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> idx(256, -1);
        int n = s.size();
        if(n == 0) return 0;
        int ct = 1;
        int mx = 1;
        int l = 0;
        idx[s[l]] = l;
        for(int r = 1; r < n; r++) {
            if(idx[s[r]] < l) {
                idx[s[r]] = r;
                ct++;
            } else {
                mx = max(ct, mx);
                l = idx[s[r]]+1;
                idx[s[r]] = r;
                ct = (r-l+1);
            }
        }
        mx = max(mx, ct);
        return mx;
    }
};
