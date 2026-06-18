class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end()) {
            if(*it == target) return static_cast<int>(it - nums.begin());
        } 
        return -1;
    }
};
