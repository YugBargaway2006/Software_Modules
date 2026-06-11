// *** 12  :49   ::::::::::::::::: Revise
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m ;i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    vector<vector<int>> dist(n+1, vector<int>(2, 1e15));
    
    dist[1][0] = 0;
    dist[1][1] = 0;
    q.push({0, 1, 0});
    while(!q.empty()) {
        auto vec = q.top(); q.pop();
        int d = vec[0];
        int u = vec[1];
        int used = vec[2];
        if(d > dist[u][used]) continue;
        // cout << w <<" " << u << " " << mw << endl;

        for(auto [v, w] : adj[u]) {
            // No discount
            if(d + w < dist[v][used]) {
                dist[v][used] = w + d;
                q.push({dist[v][used], v, used});
            }
            // discont
            if(used == 0 && d + w/2 < dist[v][1]) {
                dist[v][1] = d + w/2;
                q.push({dist[v][1], v, 1});
            }
        }
    }
    cout << dist[n][1] << endl;
}