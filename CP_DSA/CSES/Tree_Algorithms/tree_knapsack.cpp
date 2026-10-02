#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<vector<int>>> dp;
vector<int> wt;

void dfs(int u, int parent, int k) {
    if(k == 0) return; 

    
    for(auto v : adj[u]) {
        if(v == parent) continue;
        dfs()
        // U take

    }
} 


int main(void) {
    int n, k; cin >> n >> k;
    wt.assign(n+1, 0);
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    adj.assign(n+1, {});
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dp.assign(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));


}