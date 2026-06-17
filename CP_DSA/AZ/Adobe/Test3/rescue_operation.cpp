// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void djikstra(vector<vector<pair<ll, ll>>>& adj, ll n, ll s, vector<ll>& dist) {
    priority_queue<ll, vector<ll>, greater<>> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        auto u = q.top(); q.pop();
        for(auto p : adj[u]) {
            ll v = p.first;
            ll w = p.second;
            if(dist[v] < dist[u]+w) continue;
            dist[v] = dist[u] + w;
            q.push(v);
        }
    }
}


void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n);
    for(ll i = 0; i < m; i++) {
        ll u, v, x; cin >> u >> v >> x;
        u--; v--;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    ll s, d; cin >> s >> d;
    s--; d--;
    vector<ll> stdist(n, 1e12);
    vector<ll> dedist(n, 1e12);

    djikstra(adj, n, s, stdist);
    djikstra(adj, n, d, dedist);

    ll mx = 0;
    for(ll i = 0; i < n; i++) {
        mx = max(mx, stdist[i]+1+dedist[i]);
    }
    cout << mx << endl;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}