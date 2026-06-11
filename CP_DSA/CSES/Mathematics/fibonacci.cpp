// 21 : 35
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll mod = 1e9+7;
map<ll, ll> dp;

ll calculate(ll n) {
    if(dp.count(n) != 0) return dp[n];

    ll k = n/2;
    calculate(k);
    calculate(k+1);
    if(n%2==0) {
        dp[n] = ((dp[k] % mod) * (2 * dp[k+1] % mod - dp[k] % mod)) % mod; 
    } else {
        dp[n] = (dp[k] * dp[k]) % mod + (dp[k+1] * dp[k+1]) % mod;
    }
    return dp[n] % mod;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    cout << (calculate(n) + mod) % mod << endl;
}