class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> found;
        for(auto x : nums) {
            if(found.count(x)) return true;
            found.insert(x);
        }
        return false;
    }
};