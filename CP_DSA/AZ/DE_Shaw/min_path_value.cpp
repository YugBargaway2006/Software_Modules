// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n, m; cin >> n >> m;
    ll s, e; cin >> s >> e; s--; e--;
    vector<vector<pair<ll, ll>>> adj(n);
    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v; u--; v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
    }

    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(ll i = 0; i < n; i++) {
        for(auto& p : adj[i]) {
            ll v = p.first;
            p.second = abs(arr[i] - arr[v]);
        }
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    vector<ll> dist(n, 1e15);
    q.push({0, s});
    dist[s] = 0;
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        ll u = p.second;
        ll d = p.first;
        if(d > dist[u]) continue;

        for(auto p2 : adj[u]) {
            ll v = p2.first;
            ll w = p2.second;
            ll nd = max(dist[u], w);
            if(nd < dist[v]) {
                dist[v] = nd;
                q.push({nd, v});
            }
        }
    }

    if(dist[e] == 1e15) cout << -1 << endl;
    else cout << dist[e] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}