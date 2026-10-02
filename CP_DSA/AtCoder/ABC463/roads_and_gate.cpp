#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, y; cin >> n >> m >> y;
    vector<vector<pair<ll, ll>>> adj(n+2);
    for(ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    } 

    adj[n].push_back({n+1, y});
    adj[n+1].push_back({n, y});

    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        adj[i].push_back({n, x});
        adj[n+1].push_back({i, x});
    }

    vector<ll> dist(n+2, 1e15);
    priority_queue<pair<ll ,ll>, vector<pair<ll, ll>>, greater<>> q;
    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if(dist[u] < d) continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            q.push({dist[v], v});
        }
    }

    for(ll i = 1; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}