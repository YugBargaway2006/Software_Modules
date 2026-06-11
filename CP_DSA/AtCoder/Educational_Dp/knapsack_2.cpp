// http://atcoder.jp/contests/dp/tasks
// 21 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, w; cin >> n >> w;
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<ll> dp(1e5+1, INT_MAX);
    dp[0] = 0;
    for(ll j = 0; j < n; j++) {
        for(ll i = 1e5; i >= arr[j].second; i--) {
            dp[i] = min(dp[i], dp[i-arr[j].second] + arr[j].first);
        } 
    }

    for(ll i = 100000; i >= 0; i--) {
        if(dp[i] <= w) {
            cout << i << endl; return 0;
        } 
    }
}