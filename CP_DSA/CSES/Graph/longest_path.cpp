// 19 : 08
#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<bool> reach(n+1, false);
    queue<int> rq; rq.push(1); reach[1] = true;
    while(!rq.empty()) {
        int u = rq.front(); rq.pop();
        for(auto v : adj[u]) {
            if(reach[v]) continue; 
            rq.push(v);
            reach[v] = true;
        }
    }

    if(!reach[n]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> inorder(n+1, 0);
    for(int u = 1; u <= n; u++) {
        for(auto v : adj[u]) {
            inorder[v]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) if(inorder[i] == 0) q.push(i);
    vector<int> traver;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        traver.push_back(u);
        for(auto v : adj[u]) {
            inorder[v]--;
            if(inorder[v] == 0) q.push(v);
        }
    }

    vector<int> dist(n+1, -1);
    vector<int> parent(n+1, -1);
    dist[1] = 0;
    parent[1] = 1;
    for(auto u : traver) {
        for(auto v : adj[u]) {
            if(dist[u] != -1 && dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    if(dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dist[n] + 1 << endl;
    vector<int> path;
    for(int u = n; u != 1; u = parent[u]) {
        path.push_back(u);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(auto u : path) cout << u << " ";
    cout << endl;
} 