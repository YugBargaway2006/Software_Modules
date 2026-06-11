// 13 : 45
#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'

vector<vector<int>> board(9, vector<int>(9, 0));
vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

int degree(int x, int y) {
    int cnt = 0;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && ny >= 1 &&
            nx <= 8 && ny <= 8 &&
            board[nx][ny] == 0)
        {
            cnt++;
        }
    }

    return cnt;
}


bool path(int x, int y, int count) {
    if(x < 1 || y < 1 || x > 8 || y > 8) return false;
    if(board[x][y] != 0) return false;
    
    if(count == 64) {
        board[x][y] = count;
        return true;
    }

    board[x][y] = count;
    priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8 && board[nx][ny] == 0) {
            q.push({degree(nx, ny), nx, ny});
        }
    }

    while(!q.empty()) {
        auto v = q.top(); q.pop();
        if(path(v[1], v[2], count+1)) return true;
    }
    board[x][y] = 0;
    return false;
}

signed main(void) {
    int x, y;
    cin >> x >> y;

    if (path(x, y, 1)) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cout << board[j][i] << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "No solution\n";
    }
}