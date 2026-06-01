// 00 : 10 ::::::::::::::::: REPEAT
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> adj;
int si, sj;
vector<vector<int>> md;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

char find(int u, int v, pair<int, int>& p) {
    if(u == p.first-1) return 'U';
    if(u == p.first+1) return 'D';
    if(v == p.second+1) return 'R';
    if(v == p.second-1) return 'L';
    return 'X';
}

signed int main(void) {
    int n, m; cin >> n >> m;
    adj.assign(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == 'A') {
                si = i, sj = j;
            }
        }
    }
    {
        md.assign(n, vector<int>(m, 1e8));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(adj[i][j] != 'M') continue;
                q.push({i, j});
                md[i][j] = 0;
                vis[i][j] = true;
            }
        }
    
        // q.push({i, j});
        while(!q.empty()) {
            auto& [u, v] = q.front();
            q.pop();
            // if(vis[u][v]) continue;

            for(int i = 0; i < 4; i++) {
                int x = u + dx[i];
                int y = v + dy[i];
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                if(vis[x][y]) continue;
                if(adj[x][y] == '#') continue;
                vis[x][y] = true;
                q.push({x, y});
                md[x][y] =  md[u][v] + 1;
            }
        }
    }

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<int>> ad(n, vector<int>(m, 1e8));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {si, sj};
    int fi, fj;
    ad[si][sj] = 0;
    bool done = false;
    while(!done && !q.empty()) {
        auto [u, v] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int x = u + dx[i];
            int y = v + dy[i];
            if(x < 0 || y < 0 || x >= n || y >= m) {
                fi = u, fj = v;
                done = true;
                break;
            }
            if(vis[x][y]) continue;
            if(adj[x][y] == '#') continue;
            vis[x][y] = true;
            if(ad[u][v] + 1 >= md[x][y]) continue;
            q.push({x, y});
            ad[x][y] =  ad[u][v] + 1;
            parent[x][y] = {u, v};
        }
    }

    if(!done) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    string path = "";
    int u = fi, v = fj;
    while(!(u == si && v == sj)) {
        auto p = parent[u][v];
        path += find(u, v, p);
        u = p.first;
        v = p.second;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    cout << path << endl;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << ad[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}

// 00 : 50