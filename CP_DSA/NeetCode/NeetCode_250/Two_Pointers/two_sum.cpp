class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int got = numbers[l] + numbers[r];
            if(got == target) return {l+1, r+1};
            else if(got < target) l++;
            else r--; 
        }
    }
};
