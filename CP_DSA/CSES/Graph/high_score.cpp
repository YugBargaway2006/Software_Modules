// ** 12 : 22 ::::::::::::::::::::::: Revise
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({y, -z});
        // adj[y].push_back({x, -z});
    } 

    vector<vector<int>> rev(n+1);
    vector<bool> reachn(n+1, false);
    for(int u = 1; u <= n; u++) {
        for(auto [v, _] : adj[u]) {
            rev[v].push_back(u);
        }
    }

    queue<int> q;
    reachn[n] = true;
    q.push(n);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : rev[u]) {
            if(reachn[v]) continue;
            reachn[v] = true;
            q.push(v);
        }
    }

    vector<bool> reach1(n+1, false);

    q.empty();
    reach1[1] = true;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto [v, _] : adj[u]) {
            if(reach1[v]) continue;
            reach1[v] = true;
            q.push(v);
        }
    }

    vector<int> dist(n+1, 1e15);
    dist[1] = 0;
    for(int i = 0; i < n-1; i++) {
        for(int u = 1; u <= n; u++) {
            for(auto [v, w] : adj[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for(int u = 1; u <= n; u++) {
        for(auto [v, w] : adj[u]) {
            if(dist[u] != 1e15 && dist[u] + w < dist[v] && reachn[v] && reach1[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << -dist[n] << endl;
}

// 12 : 45