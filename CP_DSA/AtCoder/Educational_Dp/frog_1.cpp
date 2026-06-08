// http://atcoder.jp/contests/dp/tasks
// 21 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> dp(n, 1e15);
    dp[0] = 0;
    for(ll i = 1; i < n; i++) {
        dp[i] = min(dp[i], dp[i-1] + abs(arr[i] - arr[i-1]));
        if(i-2 >= 0) dp[i] = min(dp[i], dp[i-2] + abs(arr[i] - arr[i-2]));
    }
    cout << dp[n-1] << endl;
}