// http://atcoder.jp/contests/dp/tasks
// 21 : 53
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'



signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));    
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    if(arr[0][0] == '#') {
        cout << 0 << endl;
    }

    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    ll mod = 1e9+7;
    dp[0][0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(arr[i][j] == '#') dp[i][j] = 0;
            else {
                if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
}