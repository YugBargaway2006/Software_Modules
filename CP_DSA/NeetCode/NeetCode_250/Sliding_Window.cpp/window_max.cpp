class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            while(!q.empty() && q.back().first <= x) {
                q.pop_back();
            }

            q.push_back({x, i});

            while(!q.empty() && q.front().second <= i - k) {
                q.pop_front();
            }

            if(i >= k-1) {
                ans.push_back(q.front().first);
            }
        }
        return ans;
    }
};
