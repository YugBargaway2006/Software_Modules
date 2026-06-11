// *** 18 : 53
#include <bits/stdc++.h>
using namespace std;

signed main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x  >> y;
        adj[x].push_back(y);
    }

    vector<int> indegree(n+1, 0);
    for(int u = 1; u <= n; u++) {
        for(auto v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> traversal;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        traversal.push_back(u);

        for(auto v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    } 

    if(traversal.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(auto d : traversal) cout << d << " ";
        cout << endl;
    }
}

// 18 : 58