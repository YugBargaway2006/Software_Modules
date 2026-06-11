// http://atcoder.jp/contests/dp/tasks
// 21 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> dp(n, 1e15);
    dp[0] = 0;
    for(ll i = 1; i < n; i++) {
        for(ll j = 1; j <= k; j++) {
            if(i-j >= 0) dp[i] = min(dp[i], dp[i-j] + abs(arr[i] - arr[i-j]));
        }
    }
    cout << dp[n-1] << endl;
}