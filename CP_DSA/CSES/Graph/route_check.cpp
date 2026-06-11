#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void dfs1(int u, vector<vector<int>>& adj,
          vector<bool>& vis, vector<int>& order) {
    vis[u] = true;

    for(auto v : adj[u]) {
        if(!vis[v]) dfs1(v, adj, vis, order);
    }

    order.push_back(u); // finish time
}

void dfs2(int u, vector<vector<int>>& rev,
          vector<bool>& vis, vector<int>& comp) {
    vis[u] = true;
    comp.push_back(u);

    for(auto v : rev[u]) {
        if(!vis[v]) dfs2(v, rev, vis, comp);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1), rev(n+1);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        rev[y].push_back(x);
    }

    vector<bool> vis(n+1, false);
    vector<int> order;

    // first pass
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs1(i, adj, vis, order);
        }
    }

    reverse(order.begin(), order.end());

    // second pass
    vis.assign(n+1, false);

    vector<vector<int>> scc;

    for(auto u : order) {
        if(vis[u]) continue;

        vector<int> comp;
        dfs2(u, rev, vis, comp);

        scc.push_back(comp);
    }

    if(scc.size() == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
        cout << scc[1][0] << " " << scc[0][0] << endl;
    }
}