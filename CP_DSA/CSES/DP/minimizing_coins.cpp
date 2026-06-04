// 12 : 04
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, x;
ll mx = INT_MAX;
vector<ll> c;
vector<ll> dp;

ll filldp(ll p) {
    if(p <= 0) return 0;
    if(dp[p] != -1) return dp[p];
    dp[p] = mx;

    for(auto ci : c) {
        if(p - ci < 0) continue;
        dp[p] = min(dp[p], filldp(p - ci) + 1);
    }

    return dp[p];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    c.assign(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    dp.assign(x+1, -1);

    ll ans = filldp(x);

    // for(auto i : dp) cout << i << " ";
    // cout << endl;

    if(ans == mx) cout << -1 << endl;
    else cout << ans << endl;
}