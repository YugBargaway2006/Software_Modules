class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<int> suf_max(n);
        suf_max[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--) {
            suf_max[i] = max(prices[i], suf_max[i+1]);
        }
        // for(auto x : suf_max) cerr << x << " "; cerr << endl;
        for(int i = 0; i < n; i++) {
            profit = max(profit, suf_max[i] - prices[i]);
        }
        return profit;
    }
};
