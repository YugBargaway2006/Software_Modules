// http://atcoder.jp/contests/dp/tasks
// 21 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m;
vector<vector<ll>> adj;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.assign(n, {});

    vector<ll> indegree(n, 0);
    for(ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        adj[x-1].push_back(y-1);
        indegree[y-1]++;
    }

    queue<ll> q;
    vector<ll> inorder;
    for(ll i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        inorder.push_back(u);
        for(auto v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // for(auto x : inorder) cout << x <<  " "; cout << endl;

    ll mxd = 0;
    vector<ll> dist(n, 0);
    for(auto u : inorder) {
        for(auto v : adj[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
            mxd = max(mxd, dist[v]);
        }
    }

    cout << mxd << endl;
}