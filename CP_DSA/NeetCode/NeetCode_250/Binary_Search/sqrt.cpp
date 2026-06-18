class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = 1e9;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            long long v0 = (mid-1)*(mid-1);
            long long v1 = mid*mid;

            if(x == v1) return mid;
            else if(x < v1 && x >= v0) return mid-1;
            else if(x < v0) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }   
};