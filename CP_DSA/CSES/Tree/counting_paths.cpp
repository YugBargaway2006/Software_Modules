// 16 : 13   :::::::: Long code, good formulation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m;
vector<vector<ll>> adj;
vector<ll> counter;
vector<ll> parent;
vector<ll> depth;
vector<vector<ll>> bin;
ll d = 20;
vector<ll> path;

ll jump(ll x, ll k) {
    for(ll i = 0; i < d; i++) {
        if(k & (1 << i)) {
            if(x == -1) break;
            x = bin[x][i];
        }
    }
    return x;
}

ll lca(ll a, ll b) {
    if(depth[a] < depth[b]) {
        swap(a, b);
    }

    a = jump(a, depth[a] - depth[b]);
    
    if(a == b) return a;
    for(ll i = d-1; i >= 0; i--) {
        if(bin[a][i] != -1 && bin[a][i] != bin[b][i]) {
            a = bin[a][i];
            b = bin[b][i];
        }
    }
    return bin[a][0];
}

ll dfs(ll u, ll p) {
    path[u] = counter[u];
    for(auto v : adj[u]) {
        if(v == p)  continue;
        dfs(v, u);
        path[u] += path[v];
    }
    return path[u];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    adj.assign(n, {});
    parent.assign(n, -1);
    depth.assign(n, 0);
    counter.assign(n, 0);
    path.assign(n, 0);
    bin.assign(n, vector<ll>(d, -1));
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent[0] = -1;
    depth[0] = 0;
    vector<bool> vis(n, false);
    vis[0] = true;
    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(vis[v]) continue;
            parent[v] = u;
            depth[v] = depth[u]  + 1;
            vis[v] = true;
            q.push(v);
        } 
    }

    for(ll i = 0; i < d; i++) {
        for(ll j = 0; j < n; j++) {
            if(i == 0) {
                bin[j][i] = parent[j];
            } else {
                bin[j][i] = (bin[j][i-1] == -1) ? -1 : bin[bin[j][i-1]][i-1];
            }
        }
    }

    for(ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        counter[x]++;
        counter[y]++;
        ll p = lca(x, y);
        counter[p]--;
        if(parent[p] != -1) counter[parent[p]] -= 1;

        // cout << x << " " << y << " " << p << " " << parent[p] << endl;
    }

    // for(ll i = 0; i < n; i++) counter[i] = max(0LL, counter[i]);
    // cout << endl;

    dfs(0, -1);
    for(auto u : path) cout << u << " ";
    cout << endl;
}