// ** 13 : 26        :::::::::: MUST REVISE
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    vector<int> dist(n+1, 0);
    vector<int> p(n+1, -1);
    // dist[1] = 0;
    int x = -1;
    for(int i = 0; i < n; i++) {
        x = -1;
        for(int u = 1; u <= n; u++) {
            for(auto [v, d] : adj[u]) {
                if(dist[u] + d < dist[v]) {
                    x = v;
                    dist[v] = max(static_cast<int>(-1e15), dist[u] + d);
                    p[v] = u;
                }
            }
        }
    }
    if(x == -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        x = p[x];
    }

    vector<int> cycle;
    for(int v = x; ; v = p[v]) {
        cycle.push_back(v);
        if(v == x && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());
    for(auto u : cycle) cout << u << " ";
    cout << endl;

}