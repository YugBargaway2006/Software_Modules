#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;
vector<pair<int,int>> roads;

int max_flow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);

    while (true) {
        fill(parent.begin(), parent.end(), -1);

        queue<pair<int,int>> q;
        q.push({s, LLONG_MAX});
        parent[s] = -2;

        int new_flow = 0;

        while (!q.empty()) {
            auto [u, f] = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] != -1) continue;
                if (capacity[u][v] <= 0) continue;

                parent[v] = u;

                int nf = min(f, capacity[u][v]);

                if (v == t) {
                    new_flow = nf;
                    break;
                }

                q.push({v, nf});
            }

            if (new_flow) break;
        }

        if (!new_flow) break;

        flow += new_flow;

        int cur = t;
        while (cur != s) {
            int prev = parent[cur];

            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;

            cur = prev;
        }
    }

    return flow;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    capacity.assign(n, vector<int>(n, 0));
    adj.assign(n, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        roads.push_back({a, b});

        adj[a].push_back(b);
        adj[b].push_back(a);

        capacity[a][b] += 1;
        capacity[b][a] += 1;
    }

    int flow = max_flow(0, n - 1);

    vector<int> reach(n, 0);
    queue<int> q;

    q.push(0);
    reach[0] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (reach[v]) continue;
            if (capacity[u][v] <= 0) continue;

            reach[v] = 1;
            q.push(v);
        }
    }

    cout << flow << '\n';

    for (auto [u, v] : roads) {
        if (reach[u] != reach[v]) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }
}