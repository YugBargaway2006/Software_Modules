// 23 : 01 ::::::::::::: Remember the DP forumulationk
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> arr(n);
    ll total = 0;

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (ll i = 0; i < n; i++) {
        dp[i][i] = arr[i];
    }

    for (ll len = 2; len <= n; len++) {
        for (ll l = 0; l + len - 1 < n; l++) {
            ll r = l + len - 1;

            dp[l][r] = max(
                arr[l] - dp[l + 1][r],
                arr[r] - dp[l][r - 1]
            );
        }
    }

    cout << (total + dp[0][n - 1]) / 2 << endl;
}