class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> store = nums;
        int n = nums.size(); 
        for(int i = 0; i < n; i++) {
            nums[i] = store[(((i-k) % n) + n) % n];
        }
    }
};