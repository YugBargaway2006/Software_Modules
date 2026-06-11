// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long double
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] * (1 - arr[i-1]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j-1] * (arr[i-1]) + dp[i-1][j] * (1 - arr[i-1]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    ll ans = 0;
    for(int i = (n+1)/2; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << setprecision(9) << ans << endl;

}