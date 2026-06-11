// 19 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<vector<ll>> adj;
vector<ll> dp, nc;

void dfs(ll u, ll p) {
    dp[u] = 0; nc[u] = 1;
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        nc[u] += nc[v];
        dp[u] += (dp[v] + nc[v]);
    }
}

void count(ll u, ll p) {
    for(auto v : adj[u]) {
        if(v == p) continue;
        dp[v] = dp[u] - (dp[v] + nc[v]) + (n - nc[v]) + dp[v];

        count(v, u);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.assign(n, {});
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x>> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dp.assign(n, 0);
    nc.assign(n, 0);

    dfs(0, -1);
    count(0, -1);
    for(auto x : dp) cout << x << " "; cout << endl;
    // for(auto x : nc) cout << x << " "; cout << endl;


}