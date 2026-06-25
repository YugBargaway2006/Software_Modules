// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, mt; cin >> n >> m >> mt;
    vector<ll> arr(n);
    for(auto& x : arr) {
        cin >> x;
    }

    vector<vector<pair<ll, ll>>> adj(n);
    for(ll i = 0; i < m; i++) {
        ll u, v, t; cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    vector<ll> dist(n, 1e12);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        ll u = p.second;
        ll d = p.first;
        if(d > dist[u]) continue;
        for (auto p : adj[u]) {
            ll v = p.first;
            ll w = p.second;
            if(dist[v] <= dist[u]+w) continue;
            dist[v] = dist[u] + w;
            q.push({dist[v], v});
        }
    }

    vector<int> vis(n,0);
    vis[0] = 1;

    ll ans = arr[0];

    function<void(int,int,ll)> dfs = [&](int u, int t, ll cur) {

        if (u == 0)
            ans = max(ans, cur);

        for (auto p : adj[u]) {
            ll v = p.first;
            ll w = p.second;

            if (t + w > mt)
                continue;

            // Can't even return home afterwards
            if (t + w + dist[v] > mt)
                continue;

            bool first = !vis[v];

            if (first) {
                vis[v] = 1;
                dfs(v, t + w, cur + arr[v]);
                vis[v] = 0;
            }
            else {
                dfs(v, t + w, cur);
            }
        }
    };

    dfs(0, 0, arr[0]);

    cout << ans << '\n';

} 