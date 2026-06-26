// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

vector<vector<pair<ll, ll>>> adj;
vector<ll> dist;
set<ll> out;

void solve() {
    out.clear();
    ll mxn = 101;
    adj.assign(mxn, {});
    dist.assign(mxn, 1e12);

    ll n; cin >> n;
    for(ll i = 0; i  < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back({v, 0});
        out.insert(u);
    }
    ll m; cin >> m;
    for(ll i = 0; i  < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back({v, 0});
        out.insert(u);
    }

    for(ll i = 1; i < mxn; i++) {
        for(ll j = i+1; j < min(mxn, i+7); j++) {
            if(out.count(i) != 0) continue;
            adj[i].push_back({j, 1});
            // cout << i << " " << j << endl;
        }
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(!q.empty()) {
        auto p = q.top(); q.pop();
        auto d = p.first;
        auto u = p.second;

        if(d != dist[u]) continue;
        for(auto p : adj[u]) {
            ll v = p.first;
            ll w = p.second;

            if(dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            q.push({dist[v], v});
        }
    }

    if(dist[100] == 1e12)
        cout << -1 << endl;
    else
        cout << dist[100] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}