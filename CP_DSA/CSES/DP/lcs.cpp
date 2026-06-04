// 18 : 17 :::::::::: LCS toh yaad hona hi chahiye
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> arr(n), brr(m);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    for(ll i = 0; i < m; i++) cin >> brr[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(arr[i-1] == brr[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[n][m] << endl;   

    // Reconstruct;
    vector<ll> recon;
    ll i = n, j = m;
    while(dp[i][j] != 0) {
        if(dp[i-1][j-1] + 1 == dp[i][j] && arr[i-1] == brr[j-1]) {
            recon.push_back(arr[i-1]);
            i--; j--;
            continue;
        }
        if(dp[i-1][j] == dp[i][j]) i--;
        else j--;
    }
    reverse(recon.begin(), recon.end());
    for(auto p : recon) cout << p << " "; cout << endl;
}