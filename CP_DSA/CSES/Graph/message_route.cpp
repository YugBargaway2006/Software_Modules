// ** 18 : 00 
#include <bits/stdc++.h>
using namespace std;

void reconstruct(vector<int>& parent, vector<int>& path, int i) {
    // cout << i << " " << parent[i] << endl;
    if(parent[i] == i) return;
    path.push_back(parent[i]);
    reconstruct(parent, path, parent[i]);
}

signed int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    vector<bool> vis(n+1, false);
    q.push(1);
    vector<int> parent(n+1, -1);
    // int p = 1;
    parent[1] = 1;
    vis[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        // if(vis[u]) continue;
        // vis[u] = true;
        for(auto v : adj[u]) {
            if(!vis[v]) {
                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
        }
    }

    if(parent[n] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        vector<int> path;
        reconstruct(parent, path, n);
        cout << path.size() + 1 << endl;
        for(int i = path.size()-1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << n << endl;
    }
}

// 18 : 16