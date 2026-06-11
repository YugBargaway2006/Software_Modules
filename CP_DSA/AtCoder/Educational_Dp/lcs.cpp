// http://atcoder.jp/contests/dp/tasks
// 21 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    string s, t; cin >> s >> t;
    n = s.length(); m = t.length();
    ll mx = 3001;

    vector<vector<ll>> dp(mx, vector<ll>(mx, 0));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (s[i-1] == t[j-1]));
        }
    }
    // cout << dp[n][m] << endl;

    string ans = "";
    ll i = n, j = m;
    while(dp[i][j] != 0) {
        if(s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--; j--;
        } else {
            if(dp[i-1][j] == dp[i][j]) i--;
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}