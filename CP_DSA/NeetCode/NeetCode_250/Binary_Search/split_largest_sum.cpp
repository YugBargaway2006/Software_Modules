class Solution {
public:
    bool check(vector<int>& arr, int k, int sum) {
        int ct = 0;
        int n = arr.size();
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > sum) return false;
            if(cur+arr[i] > sum) {
                ct++;
                cur = 0;
            }
            cur += arr[i];
        }
        if(cur != 0) ct++;
        return ct <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = 1e9;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            bool c1 = check(nums, k, mid-1);
            bool c2 = check(nums, k, mid);

            if(!c1 && c2) return mid;
            else if(c1 && c2) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};