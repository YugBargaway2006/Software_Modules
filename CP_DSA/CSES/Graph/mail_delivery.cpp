// ** ::::::::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<pair<int,int>>> adj;
vector<bool> used;
vector<int> path;

void dfs(int u) {
    while (!adj[u].empty()) {
        auto [v, id] = adj[u].back();
        adj[u].pop_back();

        if (used[id]) continue;
        used[id] = true;

        dfs(v);
    }
    path.push_back(u);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.assign(n, {});
    used.assign(m, false);

    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        adj[x].push_back({y, i});
        adj[y].push_back({x, i});

        deg[x]++;
        deg[y]++;
    }

    for (int node = 0; node < n; node++) {
		if (deg[node] % 2) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

    int st = 0;

    dfs(st);
    reverse(path.begin(), path.end());

    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto x : path)
        cout << x+1 << " ";
    cout << "\n";
}