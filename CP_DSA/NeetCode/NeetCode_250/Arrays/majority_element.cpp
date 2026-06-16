class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi = -1;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                candi = nums[i];
            }
            if(nums[i] == candi) {
                count++;
            } else {
                count--;
            }
        }
        return candi;
    }
};