#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<vector<pair<ll, ll>>> adj;
vector<ll> tin, low;
vector<pair<ll, ll>> bridges;
vector<bool> vis;
ll timer = 0;

void dfs(ll u, ll parentEdge = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;

    for (auto e : adj[u]) {
        ll v = e.first;
        ll id = e.second;

        if (id == parentEdge) continue;

        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, id);
            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u])
                bridges.push_back(make_pair(u, v));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    adj.assign(n, vector<pair<ll, ll>>());

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(make_pair(v, i));
        adj[v].push_back(make_pair(u, i));
    }

    tin.assign(n, -1);
    low.assign(n, -1);
    vis.assign(n, false);
    bridges.clear();
    timer = 0;

    for (ll i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);

    sort(bridges.begin(), bridges.end());

    for (auto p : bridges)
        cout << p.first + 1 << " " << p.second + 1 << '\n';

    return 0;
}