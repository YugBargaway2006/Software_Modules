class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i = 0, j = 0;
        swap(n, m);
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]);
        }
        while(i < n) {
            res.push_back(nums1[i++]);
        }
        while(j < m) {
            res.push_back(nums2[j++]);
        }
        nums1 = res;
    }
};