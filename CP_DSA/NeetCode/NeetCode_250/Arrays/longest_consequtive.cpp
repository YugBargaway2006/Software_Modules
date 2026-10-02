class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());

        int mx = 0;
        int ct = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]+1) {
                ct++;
                mx = max(mx, ct);
            }
            else if(nums[i] == nums[i-1]) continue;
            else {
                ct = 1;
            }
        }
        mx = max(mx, ct);
        return mx;
    }
};
