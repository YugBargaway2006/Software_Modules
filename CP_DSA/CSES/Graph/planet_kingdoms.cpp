#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> adj;
vector<vector<int>> rev;
int n, m;
vector<int> tra1;
vector<bool> vis1;
vector<vector<int>> scc;
vector<bool> vis2;

void dfs1(int s) {
    if(vis1[s]) return;
    vis1[s] = true;
    for(auto v : adj[s]) {
        dfs1(v);
    }
    tra1.push_back(s);
}

void dfs2(int s, vector<int>& tra2) {
    if(vis2[s]) return;
    vis2[s] = true;
    for(auto v : rev[s]) {
        dfs2(v, tra2);
    }
    tra2.push_back(s);
}

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n+1, vector<int>{});
    rev.assign(n+1, vector<int>{});
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }

    vis1.assign(n+1, false);
    for(int i =1; i <= n; i++) {
        if(vis1[i]) continue;
        dfs1(i);
    }

    // for(auto u : tra1) cout << u << " ";
    // cout << endl;

    reverse(tra1.begin(), tra1.end());
    vis2.assign(n+1, false);
    for(auto u : tra1) {
        if(vis2[u]) continue;
        vector<int> tra2;
        dfs2(u, tra2);
        // for(auto u : tra2) cout << u << " ";
        // cout << endl;
        scc.push_back(tra2);
    }   

    vector<int> kd(n, 0);
    for(int i = 0; i < scc.size(); i++) {
        for(auto u : scc[i]) {
            kd[u-1] = i+1;
        }
    }

    cout << scc.size() << endl;
    for(auto u : kd) cout << u << " ";
    cout << endl;
}