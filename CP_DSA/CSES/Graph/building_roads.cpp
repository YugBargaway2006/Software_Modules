// 17 : 54
#include <bits/stdc++.h>
using namespace std;

signed int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n+1, false);
    vector<vector<int>> path;
    for(int i = 1; i <= n; i++) {
        vector<int> cp;
        if(vis[i]) continue;
        int s = i;

        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            cp.push_back(u);
            for(auto v : adj[u]) {
                q.push(v);
            }
        }
        path.push_back(cp);
    }

    cout << path.size() -1 << endl;
    for(int i = 0; i < path.size()-1; i++) {
        cout << path[i][0] << " " << path[i+1][0] << endl;
    }
}

// 17:59