// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll n;
vector<vector<ll>> adj;
vector<vector<ll>> dist;

ll dfs(ll u, ll p, ll d, ll i) {
    dist[u][i] = d;
    ll opt = -1;
    for(auto v : adj[u]) {
        if(v == p) continue;
        ll x = dfs(v, u, d+1, i);
        if(opt == -1 || dist[x][i] > dist[opt][i]) opt = x;
    }
    return (opt == -1) ? u : opt;
}

void solve() {
    cin >> n;
    adj.assign(n, {});
    dist.assign(n, vector<ll>(2, 0));

    for(ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v; 
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll mx1 = dfs(0, 0, 0, 0);
    ll mx2 = dfs(mx1, mx1, 0, 0);
    dfs(mx2, mx2, 0, 1);

    ll mx = 0;
    for(ll i = 0; i < n; i++) {
        dist[i][0] = max(dist[i][0], dist[i][1]);
        mx = max(mx, dist[i][0]);
    }

    for(ll i = 0; i < n; i++) {
        if(dist[i][0] == mx) cout << 1 << " ";
        else cout << "0 "; 
    }
    cout << endl;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}