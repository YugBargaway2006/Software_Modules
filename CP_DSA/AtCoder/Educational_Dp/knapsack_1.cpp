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

    vector<ll> dp(w+1, 0);
    dp[0] = 0;
    for(ll j = 0; j < n; j++) {
        for(ll i = w; i >= arr[j].first; i--) {
            dp[i] = max(dp[i], dp[i-arr[j].first] + arr[j].second);
        } 
    }
    cout << dp[w] << endl;
}