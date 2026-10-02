// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n, m, s, t; cin >> n >> m >> s >> t;
    s--; t--;
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v; 
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(s == t) {
        cout << 1 << endl;
        return;
    }

    queue<ll> q;
    vector<bool> vis(n, false);
    vector<ll> dists(n, 0);
    q.push(s);
    vis[s] = true;
    dists[s] = 0;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
            dists[v] = dists[u] + 1;
        }
    }
    if(dists[t] == 0) {
        cout << -1 << endl;
        return;
    }

    vis.assign(n, false);
    vector<ll> distt(n, 0);
    q.push(t);
    vis[t] = true;
    distt[t] = 0;
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
            distt[v] = distt[u] + 1;
        }
    }

    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        if(dists[i] + distt[i] == dists[t]) ct++;
    }
    cout << ct << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}