// ** 23:57   ::::::::::::: Revise
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int st = -1, en = -1;

bool dfs(int v) {
    color[v] = 1;
    for(int u : adj[v]) {
        if(color[u] == 0) {
            parent[u] = v;
            if(dfs(u)) return true;
        }
        else if(color[u] == 1) {
            en = v;
            st = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

signed int main(void) {
    int n, m; cin >> n >> m;
    adj.assign(n+1, {});
    color.assign(n+1, 0);
    parent.assign(n+1, -1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0 && dfs(i)) break;
    }

    if(st == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    } else {
        vector<int> cycle;
        cycle.push_back(st);
        for(int u = en; u != st; u = parent[u]) {
            cycle.push_back(u);
        }
        cycle.push_back(st);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for(auto i : cycle) {
            cout << i << " ";
        }
        cout << endl;
    }
}
