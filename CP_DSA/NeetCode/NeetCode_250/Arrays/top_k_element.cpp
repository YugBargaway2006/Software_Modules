class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int mxn = 2e3+1;
        int of = 1e3;
        int n = nums.size();
        vector<int> freq(mxn, 0);
        for(int i = 0; i < n; i++) {
            freq[nums[i]+of]++;
        }

        priority_queue<pair<int, int>> q;
        for(int i = 0; i < mxn; i++) {
            q.push({freq[i], i});
        }

        vector<int> res;
        for(int i = 0; i < k; i++) {
            auto [u, v] = q.top(); q.pop();
            res.push_back(v-of);
        }
        return res;
    }
};
