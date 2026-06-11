// ::::::::::::: REVISE  (Heirholzer Algorithm, Eulerian Circuit)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m;
vector<vector<pair<ll, ll>>> adj;
vector<ll> deg;
vector<bool> vis;
vector<ll> path;

void dfs(ll u) {
    while(!adj[u].empty()) {
        auto [v, i] = adj[u].back();
        adj[u].pop_back();

        if(vis[i]) continue;
        vis[i] = true;

        dfs(v);
    }
    path.push_back(u);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.assign(n, {});
    vis.assign(m, false);
    deg.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        adj[x].push_back({y, i});
        // adj[y].push_back({x, i});

        deg[x]++;
        deg[y]++;
    }

    // for(auto i : deg) cout << i << " "; cout << endl;

    for (int node = 0; node < n; node++) {
		if ((node != 0 && node != n-1) && deg[node] % 2 == 1) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		} else if ((node == 0 || node == n-1) && (deg[node] % 2 == 0)) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

    int st = 0;

    dfs(st);
    reverse(path.begin(), path.end());

    if ((int)path.size() != m + 1 || path[path.size()-1] != n-1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto x : path)
        cout << x+1 << " ";
    cout << "\n";
}