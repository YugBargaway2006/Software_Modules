// 00 : 09
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m; cin >> n >> m;
    int mod = 1e9+7;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev(n+1);
    for(int i = 0; i < m; i++) {
        int x, y; cin>> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }

    vector<int> indegree(n+1, 0);
    for(int u = 1; u <= n; u++) {
        for(auto v : adj[u]) indegree[v]++;
    }

    queue<int> q;
    for(int i =1; i <= n; i++) if(indegree[i] == 0) q.push(i);

    vector<int> traversal;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        traversal.push_back(u);
        for(auto v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    vector<int> paths(n+1, 0);
    paths[1] = 1;
    for(auto v : traversal) {
        for(auto u : rev[v]) {
            paths[v] += paths[u] % mod;
            paths[v] %= mod;
        }
    }

    cout << paths[n] % mod << endl;
}

// 00 : 15