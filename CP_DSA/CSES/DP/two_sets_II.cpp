// 21 : 32  ::::: Solved using Generating Function Recurrence Relation. Revise
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    if(n*(n+1) % 4 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll mod = 1e9+7;

    ll tar = n*(n+1)/4;
    vector<vector<ll>> dp(n+1, vector<ll>(tar+1, 0));
    dp[0][0] = 1;
    for(ll i = 1; i < n+1; i++) {
        for(ll j = 0; j <= tar; j++) {
            dp[i][j] = dp[i-1][j] % mod;
            if(j >= i) dp[i][j] += dp[i-1][j-i] % mod; 
        }
    }

    // for(auto p : dp) {
    //     for(auto v : p) cout << v << " "; cout << endl;
    // }
    cout << dp[n][tar]/2 % mod << endl;
}