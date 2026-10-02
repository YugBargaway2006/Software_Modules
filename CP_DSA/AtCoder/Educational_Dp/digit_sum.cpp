// 16 : 17
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll d;
string k;
ll mod = 1e9+7;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> d;
    vector<vector<ll>> dp(d, vector<ll>(2, 0));   // <d, tight>
    vector<vector<ll>> ndp(d, vector<ll>(2, 0));   // <d, tight>
    dp[0][1] = 1;
    ll n = k.size();
    for(ll i = 0; i < n; i++) {
        for(ll r = 0; r < d; r++) {
            ndp[r][0] = 0;
            ndp[r][1] = 0;
        }
        ll lim = k[i] - '0';
        for(ll rem = 0; rem < d; rem++) {
            for(ll tight = 0; tight < 2; tight++) {
                ll cur = dp[rem][tight];
                if(cur == 0) continue;

                ll upper = tight ? lim : 9;
                for(ll digit = 0; digit <= upper; digit++) {
                    ll ntight = (tight && digit == lim);
                    ll nrem = (rem + digit) % d;
                    ndp[nrem][ntight] += cur;
                    ndp[nrem][ntight] %= mod;
                }
            }
        }
        swap(dp, ndp);
    }

    ll ans = (dp[0][0] + dp[0][1]) % mod;
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
}