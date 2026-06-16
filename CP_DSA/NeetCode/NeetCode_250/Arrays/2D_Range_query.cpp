class NumMatrix {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        prefix = matrix;
        preprocess();
    }

    void preprocess() {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0) prefix[i][j] += prefix[i-1][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j > 0) prefix[i][j] += prefix[i][j-1];
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cerr << prefix[i][j] << " ";
        //     }
        //     cerr << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix[row2][col2];
        if(row1 > 0) ans -= prefix[row1-1][col2];
        if(col1 > 0) ans -= prefix[row2][col1-1];
        if(row1 > 0 && col1 > 0) ans += prefix[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */