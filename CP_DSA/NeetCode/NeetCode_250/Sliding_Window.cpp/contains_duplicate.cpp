class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> found;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(found.count(nums[i])) return true;
            found.insert(nums[i]);
            if(i-k >= 0) {
                found.erase(nums[i-k]);
            }
        }
        return false;
    }
};