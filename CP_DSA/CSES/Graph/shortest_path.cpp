// *** 00 : 58  
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
        // adj[y].push_back({x, z});
    }

    vector<int> dist(n+1, 1e15);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        // cout << u << endl;
        if(d > dist[u]) continue;
        for(auto [v, z] : adj[u]) {
            if(dist[v] <= dist[u] + z) continue;
            dist[v] = dist[u] + z;
            q.push({dist[v], v});
        }
    }

    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
}