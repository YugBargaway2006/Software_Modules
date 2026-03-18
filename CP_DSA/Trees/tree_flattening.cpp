#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tin;
vector<int> tout;
int timer = 0;

void euler_tour(int u, int parent) {
    tin[u] = ++timer;

    for(auto v : adj[u]) {
        if(v != parent) {
            euler_tour(v, u);
        }
    }

    tout[u] = timer;
}

int main(void) {
    int n, q; cin >> n >> q;
    adj.assign(n+1, {});
    tin.assign(n+1, 0);
    tout.assign(n+1, 0);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    euler_tour(1, 0);

    while(q--) {
        int u, v; cin >> u >> v;

        if((tin[u] <= tin[v]) && (tout[u] >= tout[v])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
}