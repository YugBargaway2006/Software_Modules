class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, vector<int>> prefix;
        prefix[0].push_back(-1);
        int ct = 0;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ct += prefix[sum-k].size();
            prefix[sum].push_back(i);
        }
        return ct;
    }
};