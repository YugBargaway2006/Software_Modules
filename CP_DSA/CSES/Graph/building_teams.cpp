// ** 18 : 18
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

    vector<int> depth(n+1);
    vector<bool> vis(n+1);
    vector<int> color(n+1);
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        color[i] = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
    
            for(auto v : adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    (color[u] == 1) ? color[v] = 2 : color[v] = 1;
                }
                if(vis[v] && color[u] == color[v]) {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}

// 18 : 27