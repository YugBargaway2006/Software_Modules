// *** 17 : 53 ::::::::::::::::: Revise
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    vector<vector<int>> dist(n+1, vector<int>(k, 1e15));

    q.push({0, 1});
    dist[1][0] = 0;
    while(!q.empty()) {
        auto [d, u] = q.top(); q.pop();

        if(d > dist[u][k-1]) continue;
        // cout << u << " -> ";
        // for(auto d : dist[u]) cout << d << " ";
        // cout << endl;

        for(auto [v, w] : adj[u]) {
            // for(int i = 0; i < k; i++) {
                if(d + w < dist[v][k-1]) {
                    dist[v][k-1] = d + w;
                    sort(dist[v].begin(), dist[v].end());
                    q.push({w+d, v});
                }
            // }
            // q.push(v);
        }
    }

    for(auto d : dist[n]) cout << d << " ";
    cout << endl;

}


// 18 : 30