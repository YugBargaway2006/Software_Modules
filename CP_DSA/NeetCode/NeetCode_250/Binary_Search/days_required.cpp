class Solution {
public:
    bool check(vector<int>& weights, int days, int k) {
        int usedDays = 1;
        int currWeight = 0;

        for (int w : weights) {
            if (w > k) return false;

            if (currWeight + w <= k) {
                currWeight += w;
            } else {
                usedDays++;
                currWeight = w;
            }
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(weights, days, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};