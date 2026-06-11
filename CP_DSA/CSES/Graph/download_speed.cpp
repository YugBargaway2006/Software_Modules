// ** 14 : 22     :::::: REVISE with Visualization
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<pair<int, int>>> adj;
vector<vector<long long>> capacity;
int n, m; 
vector<vector<int>> allpath;
vector<int> path;
vector<bool> vis;
vector<int> dp;
map<pair<int, int>, int> wt;

int max_flow(int s, int e) {
    vector<int> parent(n, -1);

    auto reachable = [&]() -> bool {
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto [v, _] : adj[u]) {
                int w = capacity[u][v];
                if(w <= 0 || parent[v] != -1) continue;
                parent[v] = u;
                q.push(v);
            }
        }
        return parent[e] != -1;
    };

    int flow = 0;
    while(reachable()) {
        int u = e;
        int cf = LLONG_MAX;
        while (u != s) {
			cf = min(cf, capacity[parent[u]][u]);
			u = parent[u];
		}
		u = e;
        while(u != s) {
            capacity[parent[u]][u] -= cf;
            capacity[u][parent[u]] += cf;
            u = parent[u];
        }
        flow += cf;
        fill(parent.begin(), parent.end(), -1);
    }

    return flow;
}

signed main(void) {
    cin >> n >> m;
    adj.assign(n, {});
    capacity.assign(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
        capacity[x][y] += z;
    }

    cout << max_flow(0, n-1) << endl;
}