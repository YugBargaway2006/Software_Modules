// 12 : 18   :::::::: Remember the loop difference between I and II problems
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, x;
ll mod = 1e9+7;
ll mx = INT_MAX;
vector<ll> c, dp;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    c.assign(n, 0);
    dp.assign(x+1, 0);
    for(ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    dp[0] = 1;
    for(auto& ci : c) {
        for(ll i = ci; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - ci]); 
            if(dp[i] >= mod) dp[i] -= mod;   // Helped removed TLE :: -> THis Line
        }
    }
    cout << dp[x] << endl;
}