#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<pair<int, int>> edge;

vector<int> dfs(vector<vector<int>>& adj, int n) {
    stack<int> s;
    s.push(1);
    vector<bool> vis(n+1, false);

    vector<int> path;
    while(!s.empty()) {
        int u = s.top(); s.pop();

        if(vis[u]) continue;
        path.push_back(u);
        vis[u] = true;
        for(auto v : adj[u]) {
            s.push(v);
        }
    }
    return path;
} 

signed main(void) {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        edge.push_back({x, y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> path = dfs(adj, n);
    for(auto u : path) cout << u << " ";
    cout << endl;
}