class Solution {
public:
    bool check(vector<int>& piles, int h, int k) {
        if(k == 0) return false;
        int hrs = 0;
        for(auto x : piles) {
            hrs += ((x+k-1) / k);
        }
        return hrs <= h;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r =1e9;
        while(l <= r) {
            int mid = l + (r - l) / 2;

            bool c1 = check(piles, h, mid-1);
            bool c2 = check(piles, h, mid);

            if(!c1 && c2) return mid;
            else if(c1 && c2) r = mid-1;
            else l = mid+1;
        }

        return -1;
    }
};
