// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m, d;
vector<vector<pair<ll, ll>>> adj;

void solve() {
    cin >> n >> m >> d;

    adj.assign(n, {});

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll mn = 1e18;
    ll ans = -1;

    for (ll src = 0; src < n; src++) {

        vector<ll> dist(n, 1e18);
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            if (du != dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > du + w) {
                    dist[v] = du + w;
                    pq.push({dist[v], v});
                }
            }
        }

        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            if (i != src && dist[i] <= d)
                cnt++;
        }

        if (cnt < mn || (cnt == mn && src > ans)) {
            mn = cnt;
            ans = src;
        }
    }

    cout << ans + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
        solve();
}