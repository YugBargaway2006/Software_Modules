// 12 : 47 :::::::::: Understand the DP formulation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string sn, sm; cin >> sn >> sm;
    ll mx = 1e15;
    ll n = sn.size(), m = sm.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, mx));

    dp[0][0] = 0;
    for(ll i= 0; i <= n; i++) {
        for(ll j = 0; j <= m ;j++ ){
            if(i != 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
            if(j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            if(i!=0 && j!=0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (sn[i-1] != sm[j-1]));
            }
        }
    }

    // for(auto v : dp) {
    //     for(auto p : v) cout << p << " ";cout << endl;
    // }
    cout << dp[n][m] << endl; 
}