// 18 : 30 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mx = 1e15;
vector<vector<ll>> dp;

ll filldp(ll a, ll b) {
    if(a < b) swap(a, b);
    if(a == b) return dp[a][b] = dp[b][a] = 0;
    if(dp[a][b] != mx) return dp[a][b];

    // Cut about a;
    ll mn = mx;
    for(ll i = 1; i < a; i++) {
        mn = min(mn, filldp(i, b) + filldp(a-i, b) + 1);
    }
    for(ll i = 1; i < b; i++) {
        mn = min(mn, filldp(a, i) + filldp(a, b-i) + 1);
    }
    dp[a][b] = dp[b][a] = mn;
    return dp[a][b];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    dp.assign(a+1, vector<ll>(a+1, mx));
    for(ll i = 0; i <= a; i++) {
        dp[i][i] = 0;
    }

    cout << filldp(a, b) << endl;
}