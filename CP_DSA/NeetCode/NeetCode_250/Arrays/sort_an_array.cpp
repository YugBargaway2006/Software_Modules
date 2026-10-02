class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int mxn = 1e6+1;
        int of = 50000;
        vector<int> freq(mxn, 0);
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]+of]++;
        }

        int idx = 0;
        for(int i = 0; i < mxn; i++) {
            while(freq[i] != 0) {
                nums[idx] = i - of;
                idx++;
                freq[i]--;
            }
        }
        return nums;
    }
};