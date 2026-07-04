#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

struct st {
    ll r = 0; ll s = 0;
};

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    s = "X" + s;
    vector<ll> xrr(n+1), yrr(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> xrr[i];
        xrr[i] = -xrr[i];
    }
    for(ll i = 1; i < n; i++) {
        cin >> yrr[i];
    }
    // cout << s[n] << " " << xrr[n] << endl;

    vector<st> dp(n+1);
    dp[n].r = (s[n] == 'S')*xrr[n];
    dp[n].s = (s[n] == 'R')*xrr[n];
    // cout << dp[n].r << " " << dp[n].s << endl;

    for(ll i = n-1; i > 0; i--) {
        dp[i].s = max(dp[i+1].s, dp[i+1].r) + (s[i] == 'R')*xrr[i];
        dp[i].r = max(dp[i+1].s + yrr[i], dp[i+1].r) + (s[i] == 'S')*xrr[i];
        // cout << dp[i].r << " " << dp[i].s << endl;
    }
    cout << max(dp[1].r, dp[1].s) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}