// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n, k; cin >> n >> k;
    k--;
    ll m; cin >> m;
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<ll> depth(n, 1e6);
    queue<ll> q;
    q.push(k);
    vis[k] = true;
    depth[k] = 0;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(vis[v]) continue;
            depth[v] = depth[u] + 1;
            vis[v] = true;
            q.push(v);
        }
    }

    vector<pair<ll, ll>> ans;
    for(ll i = 0; i < n; i++) {
        ans.push_back({depth[i], i});
    }

    sort(ans.begin(), ans.end());

    for(ll i = 1; i < n; i++) {
        ll val = ans[i].first;
        if(val != 1e6) cout << ans[i].second+1 << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}