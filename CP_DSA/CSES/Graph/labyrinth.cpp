#include <bits/stdc++.h>
using namespace std;

string reconstruct(vector<vector<pair<int,int>>>& parent, int i, int j) {
    if(parent[i][j] == make_pair(i, j)) return "";

    int pi = parent[i][j].first;
    int pj = parent[i][j].second;

    char cur;
    if(pj == j-1) cur = 'R';
    else if(pj == j+1) cur = 'L';
    else if(pi == i-1) cur = 'D';
    else if(pi == i+1) cur = 'U';

    return reconstruct(parent, pi, pj) + cur;
}

int main() {
    int n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    int si, sj, fi, fj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') si = i, sj = j;
            if(grid[i][j] == 'B') fi = i, fj = j;
        }
    }

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    queue<pair<int,int>> q;

    q.push({si, sj});
    parent[si][sj] = {si, sj}; // mark visited

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if(grid[ni][nj] == '#') continue;
            if(parent[ni][nj] != make_pair(-1, -1)) continue;

            parent[ni][nj] = {i, j};
            q.push({ni, nj});
        }
    }

    if(parent[fi][fj] == make_pair(-1, -1)) {
        cout << "NO\n";
        return 0;
    }

    string path = reconstruct(parent, fi, fj);
    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}