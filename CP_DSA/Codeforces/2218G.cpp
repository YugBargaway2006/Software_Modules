// 14 : 37   :::::: Remember the formulation on Array
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


ll n, m;
vector<ll> brr;
const ll mod = 676767677;

void solve() {
    cin >> n >> m;
    brr.assign(n, 0);
    vector<ll> cnt(m, 0);
    for(ll i = 0; i < n; i++) {
        cin >> brr[i];
        cnt[brr[i]]++;
    }

    vector<ll> prefix(m+1, 0);
    for(ll i = 0; i < m; i++) {
        prefix[i+1] = prefix[i] + cnt[i];
    }

    ll ans = 1;
    for(ll i = 0; i < n; i++) {
        if(brr[i] == 0) continue;

        ll early = LLONG_MAX;
        if(i > 0) early = min(early, brr[i-1]);
        if(i+1 < n) early = min(early, brr[i+1]);
        early++;

        if(brr[i] < early) {
            ans = 0;
            break;
        }
        else if(brr[i] == early) {
            ans = (ans * prefix[brr[i]]) % mod;
        }
        else {
            ans = (ans * cnt[brr[i]-1]) % mod;
        }
    }
    cout << ans << endl;
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}