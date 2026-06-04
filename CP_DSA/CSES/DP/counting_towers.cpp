// 17 : 40 ::::::: Understand the DP forumualion
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    ll mod = 1e9+7;
    ll mn = 1e6+1;
    vector<vector<ll>> dp(mn, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(ll i = 2; i < mn; i++) {
        dp[i][0] = (4 * dp[i-1][0] + dp[i-1][1]) % mod;
        dp[i][1] = (2 * dp[i-1][1] + dp[i-1][0]) % mod;
    }

    while(t--) {
        ll n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
}