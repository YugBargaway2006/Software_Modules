#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m, k;
vector<vector<pair<ll,ll>>> adj;
vector<ll> parent;
vector<bool> vis;
vector<vector<ll>> capacity;
vector<pair<ll,ll>> edges;

bool reachable() {
    fill(parent.begin(), parent.end(), -1);
    fill(vis.begin(), vis.end(), false);

    queue<ll> q;
    q.push(0);
    vis[0] = true;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(auto [v, w] : adj[u]) {
            if(vis[v]) continue;
            if(capacity[u][v] <= 0) continue;

            vis[v] = true;
            parent[v] = u;
            q.push(v);
        }
    }

    return vis[adj.size()-1];
}

ll max_flow(ll s, ll t) {
    ll flow = 0;

    while(reachable()) {
        ll cf = LLONG_MAX;

        ll u = t;
        while(u != s) {
            cf = min(cf, capacity[parent[u]][u]);
            u = parent[u];
        }

        u = t;
        while(u != s) {
            capacity[parent[u]][u] -= cf;
            capacity[u][parent[u]] += cf;
            u = parent[u];
        }

        flow += cf;
    }

    return flow;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    ll N = 2 * max(n, m) + 2;
    ll S = 0;
    ll T = N - 1;

    adj.assign(N, {});
    capacity.assign(N, vector<ll>(N, 0));
    parent.assign(N, -1);
    vis.assign(N, false);

    for(ll a = 1; a <= n; a++) {
        ll boy = 2 * a;

        adj[S].push_back({boy, 1});
        adj[boy].push_back({S, 0});

        capacity[S][boy] = 1;
    }

    for(ll b = 1; b <= m; b++) {
        ll girl = 2 * b - 1;

        adj[girl].push_back({T, 1});
        adj[T].push_back({girl, 0});

        capacity[girl][T] = 1;
    }

    for(ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;

        ll boy = 2 * a;
        ll girl = 2 * b - 1;

        adj[boy].push_back({girl, 1});
        adj[girl].push_back({boy, 0});

        capacity[boy][girl] = 1;

        edges.push_back({a, b});
    }

    ll ans = max_flow(S, T);
    cout << ans << endl;

    set<pair<ll,ll>> printed;

    for(auto [a,b] : edges) {
        ll boy = 2*a;
        ll girl = 2*b-1;

        if(capacity[boy][girl] == 0 &&
        !printed.count({a,b})) {

            printed.insert({a,b});
            cout << a << " " << b << endl;
    }
}
}