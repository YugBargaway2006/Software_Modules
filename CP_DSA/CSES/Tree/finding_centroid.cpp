// 12 : 11
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<vector<ll>> adj;
vector<ll> parent, subtree;

void dfs(ll u, ll p) {
    subtree[u] = 1;
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        parent[v] = u;
        subtree[u] += subtree[v];
    }
}

ll check(ll u, ll p) {
    for(auto v : adj[u]) {
        if(v == p) continue;
        if(subtree[v] > n/2) {
            return check(v, u);
        }
    }
    return u;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.assign(n, {});
    parent.assign(n, -1);
    subtree.assign(n, 0);
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    cout << check(0, -1)+1 << endl;
}