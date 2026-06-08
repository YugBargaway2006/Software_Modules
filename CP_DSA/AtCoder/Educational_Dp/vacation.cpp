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
    vector<vector<ll>> arr(n, vector<ll>(3));
    for(ll i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0] = arr[0];
    for(ll i = 1; i < n; i++) {
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][1], dp[i-1][0]);
    }

    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
}