class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); int m = matrix[0].size();
        int l = 0, r = m*n-1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int res = matrix[mid/m][mid%m];
            if(res == target) return true;
            else if(res > target) r = mid-1;
            else l = mid+1;
        }
        // cerr << l << " " << r << endl;
        return false;
    }
};
