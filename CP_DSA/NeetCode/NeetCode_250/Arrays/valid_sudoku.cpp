class Solution {
public:
    vector<vector<char>> grid;
    int n = 9;

    bool check(int x, int y) {
        int val = grid[x][y] - '0';
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(grid[i][y] == grid[x][y]) count++;
        }
        if(count != 1) return false;

        count = 0;
        for(int i = 0; i < n; i++) {
            if(grid[x][i] == grid[x][y]) count++;
        }
        if(count != 1) return false;

        count = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[i+x-x%3][j+y-y%3] == grid[x][y]) count++;
            }
        }
        if(count != 1) return false;

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        grid = board;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '.') continue;
                if(!check(i, j)) return false;
            }
        }
        return true;
    }
};
