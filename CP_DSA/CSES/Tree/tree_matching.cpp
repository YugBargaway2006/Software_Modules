// 11 : 52    ::::::::::::   Revise the DP formulation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<vector<ll>> adj;
vector<vector<ll>> dp;

void count(ll u, ll p) {
    for(auto v : adj[u]) {
        if(v == p) continue;
        count(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for(auto v : adj[u]) {
        if(v == p) continue;
        dp[u][1] = max(dp[u][1], dp[v][0] + 1 + dp[u][0] - max(dp[v][0], dp[v][1]));
    }
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.resize(n);
    dp.assign(n, vector<ll>(2, 0));
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    count(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
}