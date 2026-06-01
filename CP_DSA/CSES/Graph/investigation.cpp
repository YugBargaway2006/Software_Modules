// 13 : 26 :::::::::::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m; cin >> n >> m;
    int mod = 1e9+7;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    vector<int> dist(n+1, 1e15);
    vector<int> ways(n+1, 0), mn(n+1, 1e15);
    vector<int> mx(n+1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 1});
    dist[1] = 0;
    ways[1] = 1;
    mn[1] = 0;
    mx[1] = 0;
    while(!q.empty()) {
        auto [d , u] = q.top(); q.pop();
        // cout << u << " " << d << endl;
        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[v] > d + w) {
                dist[v] = d+w;
                ways[v] = ways[u];
                mn[v] = mn[u]+1;
                mx[v] = mx[u]+1;
                q.push({dist[v], v});
            } else if(dist[v] == d + w) {
                dist[v] = d+w;
                ways[v] = (ways[v] + ways[u]) % mod;
                mn[v] = min(mn[v], mn[u]+1);
                mx[v] = max(mx[v], mx[u]+1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << mn[n] << " " << mx[n] << endl;;
} 