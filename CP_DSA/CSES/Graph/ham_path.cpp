// 13 : 23   ::::::::: NEED TO SERIOUSLY UNDERSTAND THE LOGIC
// Bitmask DP[mask][u] which tells number of path 1 -> ... -> u visiting set bits on mask
// So, for edge u -> v, if v not set in mask, add it. for each mask, for each u, for each neighbour
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int mod = 1e9+7;

signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[y-1].push_back(x-1);
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    dp[1][0] = 1;
    for(int i = 2; i < (1 << n); i++) {
        if((i & (1 << 0)) == 0) continue;
        if((i & (1 << (n-1))) && i != ((1 << n) -1)) continue;

        for(int e = 0; e < n; e++) {
            if(e == 0 && i != 1) continue;
            if((i & (1 << e)) == 0) continue;
            int prev = i ^ (1 << e);
            for(int it : adj[e]) {
                if((prev & (1 << it))) {
                    dp[i][e] += (dp[prev][it] % mod);
                    dp[i][e] %= mod;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n-1] % mod << endl;
}