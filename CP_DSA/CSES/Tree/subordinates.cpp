// 11 : 23
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<vector<ll>> adj;
vector<ll> dp;

ll count(ll i, ll p) {
    if(adj[i].empty()) {
        dp[i] = 0;
        return 1LL;
    }

    for(auto v : adj[i]) {
        if(v == p) continue;
        dp[i] += count(v, i);
    }
    return dp[i] + 1;
}

signed main(void) {
    ll n; cin >> n;
    adj.assign(n, {});
    dp.assign(n, 0);
    vector<ll> arr(n);
    for(ll i = 1; i < n; i++) {
        cin >> arr[i];
        adj[arr[i]-1].push_back(i);
    }

    // for(ll i = 0; i < n; i++) {
    //     for(auto v : adj[i]) cout << v << " ";
    //     cout << endl;
    // }

    count(0, 0);

    for(ll i = 0; i < n; i++) cout << dp[i] << " ";
    cout << endl;
}