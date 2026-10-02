// https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/party-5-1/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> adj(n);
    vector<ll> neigh(n, 0);
    for(ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        neigh[x]++;
        neigh[y]++;
    }
    
    ll ct = 0;
    queue<ll> q;
    vector<bool> rem(n, false);
    for(ll i = 0; i < n; i++) {
        if(neigh[i] < k) {
            q.push(i);
            rem[i] = true;
        }
    }
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        ct++;
        for(auto v : adj[u]) {
            if(rem[v]) continue;
            neigh[v]--;
            if(neigh[v] < k) {
                q.push(v);
                rem[v] = true;
            }
        }
    }
    cout << n - ct << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
