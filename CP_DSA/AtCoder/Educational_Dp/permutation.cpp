// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll mod = 1e9+7;
    ll n; string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    dp[1][1] = 1;
    for(ll i = 2; i <= n; i++) {
        vector<ll> pre(n+1, 0);
        for(ll j = 1; j <= n; j++) {
            pre[j] = dp[i-1][j] + pre[j-1];
        }
        for(ll j = 1; j <= i; j++) {
            if(s[i-2] == '<') {
                dp[i][j] = (((pre[j-1]) % mod) + mod) % mod;
            }
            if(s[i-2] == '>') {
                dp[i][j] = (((pre[i-1] - pre[j-1]) % mod) + mod) % mod;

            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}