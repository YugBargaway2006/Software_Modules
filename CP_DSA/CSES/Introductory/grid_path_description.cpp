// ::::::::::::::: REVISE Something called Split Grid Pruning with Video
#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[9][9];
int ans = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void dfs(int r, int c, int idx) {
    // Reached destination
    if (r == 7 && c == 1) {
        if (idx == 48) ans++;
        return;
    }

    // Used all moves but not at destination
    if (idx == 48) return;

    // Split-grid pruning
    if (vis[r - 1][c] && vis[r + 1][c] &&
        !vis[r][c - 1] && !vis[r][c + 1])
        return;

    if (vis[r][c - 1] && vis[r][c + 1] &&
        !vis[r - 1][c] && !vis[r + 1][c])
        return;

    vis[r][c] = true;

    if (s[idx] == '?') {
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (!vis[nr][nc]) {
                dfs(nr, nc, idx + 1);
            }
        }
    } else {
        int k;
        if (s[idx] == 'U') k = 0;
        else if (s[idx] == 'D') k = 1;
        else if (s[idx] == 'L') k = 2;
        else k = 3;

        int nr = r + dr[k];
        int nc = c + dc[k];

        if (!vis[nr][nc]) {
            dfs(nr, nc, idx + 1);
        }
    }

    vis[r][c] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    // Border as visited
    for (int i = 0; i < 9; i++) {
        vis[0][i] = vis[8][i] = true;
        vis[i][0] = vis[i][8] = true;
    }

    dfs(1, 1, 0);

    cout << ans << '\n';
    return 0;
}