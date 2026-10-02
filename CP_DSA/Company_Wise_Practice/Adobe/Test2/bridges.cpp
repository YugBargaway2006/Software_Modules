#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> adj;
vector<int> tin, low;
vector<pair<int,int>> bridges;
int timer = 0;

void dfs(int u, int parent) {
    tin[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;

    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!tin[i]) {
            dfs(i, -1);
        }
    }

    sort(bridges.begin(), bridges.end());

    for (auto p : bridges) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}