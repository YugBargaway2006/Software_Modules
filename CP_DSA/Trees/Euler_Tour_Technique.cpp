#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    int n;
    vector<int> bit;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    void update(int i, int delta) {
        while(i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l-1);
    }
};


vector<vector<int>> adj;
vector<int> tin, tout, flat;
int timer = 0;

void dfs(int u, int parent, vector<int>& val) {
    tin[u] = ++timer;
    flat[timer] = val[u];

    for(int v : adj[u]) {
        if(v != parent) {
            dfs(v, u, val);
        }
    }

    tout[u] = timer;
}

int main(void) {
    int n, q; cin >> n >> q;

    vector<int> val(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    adj.assign(n+1, {});
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tin.resize(n+1);
    tout.resize(n+1);
    flat.resize(n+1);

    dfs(1, 0, val);

    FenwickTree ft(n);

    for(int i = 1; i <= n; i++) {
        ft.update(i, flat[i]);
    }

    while(q--) {
        int t; cin >> t;

        if(t == 1) {
            int u, x;
            cin >> u >> x;

            int delta = x - val[u];
            val[u] = x;

            ft.update(tin[u], delta);
        }
        if(t == 2) {
            int u;
            cin >> u;
            cout << ft.rangeQuery(tin[u], tout[u]) << endl; 
        }
    }
}