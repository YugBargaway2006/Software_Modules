// 16 : 24       ::::::: A very good One
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> coins;
vector<vector<int>> adj;
vector<vector<int>> rev;
vector<bool> vis1; 
vector<int> trav1;
vector<bool> vis2;
vector<vector<int>> scc;

void dfs1(int i) {
    if(vis1[i]) return;
    vis1[i] = true;
    for(auto u : adj[i]) dfs1(u);
    trav1.push_back(i);
}

void dfs2(int i, vector<int>& trav2) {
    if(vis2[i]) return;
    vis2[i] = true;
    for(auto u : rev[i]) dfs2(u, trav2);
    trav2.push_back(i);
}

signed main(void) {
    int n, m; cin >> n >> m;
    coins.assign(n+1, 0);
    adj.assign(n+1, {});
    rev.assign(n+1, {});
    for(int i = 1; i <= n; i++) cin >> coins[i];
    for(int i = 1; i<=m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }

    vis1.assign(n+1, false);
    vis2.assign(n+1, false);

    for(int i = 1; i <= n; i++) if(!vis1[i]) dfs1(i);
    reverse(trav1.begin(), trav1.end());

    for(auto u : trav1) {
        if(!vis2[u]) {
            vector<int> trav2;
            dfs2(u, trav2);
            scc.push_back(trav2);
        }
    }

    // for(auto vec : scc) {
    //     for(auto v : vec) cout << v << " ";
    //     cout << endl;
    // }

    vector<int> label(n+1, -1);
    for(int i = 0; i < scc.size(); i++) {
        for(auto v : scc[i]) {
            label[v] = i;
        }
    }

    vector<int> points(scc.size()+1, 0);
    for(int i = 1; i <= n; i++) {
        points[label[i]] += coins[i];
    }

    vector<set<int>> sccdag(scc.size());

    for(int i = 1; i <= n; i++) {
        for(auto v : adj[i]) {
            if(label[i] != label[v]) {
                sccdag[label[i]].insert(label[v]);
            }
        }
    }

    vector<int> indeg(scc.size(), 0);
    for(int u = 0; u < scc.size(); u++) {
        for(auto v : sccdag[u]) {
            indeg[v]++;
        }
    }

    queue<int> q;
    vector<long long> dp(scc.size(), 0);

    for(int i = 0; i < scc.size(); i++) {
        dp[i] = points[i];

        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : sccdag[u]) {
            dp[v] = max(dp[v], dp[u] + points[v]);

            indeg[v]--;

            if(indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    long long ans = 0;

    for(auto x : dp) {
        ans = max(ans, x);
    }

    cout << ans << endl;

}