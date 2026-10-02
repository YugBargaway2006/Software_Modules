#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& adj, int n, int u, int parent, vector<vector<int>>& dp) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    // cerr << 1 << endl;
    for(auto v : adj[u]) {
        if(v == parent) continue;
        dfs(adj, n, v, u, dp);
        // U not taken
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

int main(void) {
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dfs(adj, n, 1, 0, dp);

    cout << min(dp[1][0], dp[1][1]) <<  endl;
}