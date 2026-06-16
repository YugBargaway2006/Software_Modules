class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> found;
        for(int  i = 0; i < nums.size(); i++) {
            if(found.count(target-nums[i])) {
                return {found[target-nums[i]], i};
            }
            found[nums[i]] = i;
        }
    }
};
