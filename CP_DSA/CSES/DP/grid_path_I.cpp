// 12 : 53
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll n; 
vector<vector<char>> adj;
vector<vector<ll>> dp;
ll mod = 1e9+7;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.assign(n, vector<char>(n));
    dp.assign(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n;j++) {
            cin >> adj[i][j];
        }
    }

    for(ll i = 0; i < n; i++) {
        if(adj[i][0] == '*') break;    // Old Logic failed here to fill up and left directly by 1;
        dp[i][0] = 1; 
    }
    for(ll i = 0; i < n; i++) {
        if(adj[0][i] == '*') break; 
        dp[0][i] = 1; 
    }

    for(ll i = 1; i < n; i++) {
        for(ll j = 1; j < n; j++) {
            dp[i][j] += (adj[i-1][j] == '*') ? 0 : dp[i-1][j] % mod;
            dp[i][j] += (adj[i][j-1] == '*') ? 0 : dp[i][j-1] % mod;
        }
    }
    if(adj[n-1][n-1] == '*') cout << 0 << endl;   // Remember the base case
    else cout << dp[n-1][n-1] % mod << endl;
}