class Solution {
public:
    using ll = long long;

    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*nums.size());
        for(ll i = 0; i < n; i++) {
            ans[i] = ans[n+i] = nums[i];
        }
        return ans;
    }
};