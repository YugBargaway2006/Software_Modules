// 14 : 07
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;
ll n;
vector<vector<ll>> adj;
vector<vector<ll>> dp;

void solve(ll u, ll p) {
    // if(adj[u].size() == 1) {
    //     dp[u] = {1, 1};
    //     return;
    // }
    dp[u] = {1, 1};
    for(auto v : adj[u]) {
        if(v == p) continue;
        solve(v, u);
        dp[u][0] = (dp[u][0] * dp[v][1]) % mod;
        dp[u][1] = (dp[u][1] * (dp[v][1]+dp[v][0])) % mod;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.assign(n+1, {});
    for(ll i = 0; i < n-1; i++ ){
        ll x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dp.assign(n+1, vector<ll>(2, 0));

    solve(1, -1);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
}