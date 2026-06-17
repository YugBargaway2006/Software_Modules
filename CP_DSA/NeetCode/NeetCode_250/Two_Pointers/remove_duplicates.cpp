class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct = 1;
        vector<int> res;
        int n = nums.size();
        if(n == 0) return 0;
        res.push_back(nums[0]);
        for(int  i =1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                ct++;
                res.push_back(nums[i]);
            }
        }
        nums = res;
        return ct;
    }
};