#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& adj, vector<int>& wt, int u, int n, vector<bool>& vis, vector<int>& dp) {
    if(vis[u]) return 0;

    dp[u] = wt[u];
    vis[u] = true;
    for(auto v : adj[u]) {
        // cout << dp[u] << " ";
        dp[u] += dfs(adj, wt, v, n, vis, dp);
        // cout << dp[u] << endl;
    }
    return dp[u];
}

int main(void) {
    int n; cin >> n;
    vector<int> wt(n+1);
    for(int i = 1; i <= n; i++) {
        cin >>  wt[i];
    }

    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n+1, false);
    vector<int> dp(n+1, 0);

    dfs(adj, wt, 1, n, vis, dp);

    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}