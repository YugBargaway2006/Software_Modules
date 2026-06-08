// 13 :10 ::: Remember the Logic and code flow
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

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
    return opt == -1 ? u : opt;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.assign(n, {});
    dist.assign(n, vector<ll>(2, 0));
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll mx1 = dfs(0, 0, 0, 0);
    ll mx2 = dfs(mx1, mx1, 0,0 );
    dfs(mx2, mx2, 0, 1);

    for(ll i = 0; i < n; i++) cout << max(dist[i][0], dist[i][1]) << " ";
    cout << endl;
}