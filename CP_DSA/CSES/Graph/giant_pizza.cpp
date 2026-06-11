// ** :::::::::::::::::::::: REVISEEEEEEEEEEEE
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> adj, rev;
vector<int> order, comp;
vector<bool> vis;

void dfs1(int v) {
    vis[v] = true;
    for(int u : adj[v])
        if(!vis[u]) dfs1(u);
    order.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for(int u : rev[v])
        if(comp[u] == -1) dfs2(u, c);
}

int id(int x, char c) {
    return 2*(x-1) + (c == '-');
}

signed main() {
    int n, m;
    cin >> n >> m;

    adj.assign(2*m, {});
    rev.assign(2*m, {});

    for(int i = 0; i < n; i++) {
        char a, b;
        int x, y;

        cin >> a >> x >> b >> y;

        int A = id(x, a);
        int B = id(y, b);

        adj[A ^ 1].push_back(B);
        adj[B ^ 1].push_back(A);

        rev[B].push_back(A ^ 1);
        rev[A].push_back(B ^ 1);
    }

    vis.assign(2*m, false);

    for(int i = 0; i < 2*m; i++)
        if(!vis[i]) dfs1(i);

    reverse(order.begin(), order.end());

    comp.assign(2*m, -1);

    int c = 0;
    for(int v : order)
        if(comp[v] == -1)
            dfs2(v, c++);

    vector<char> ans(m);

    for(int i = 0; i < m; i++) {
        if(comp[2*i] == comp[2*i+1]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        ans[i] = (comp[2*i] > comp[2*i+1]) ? '+' : '-';
    }

    for(char x : ans)
        cout << x << " ";
}