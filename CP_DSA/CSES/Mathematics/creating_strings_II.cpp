// 13 : 49  :::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;

ll modexp(ll b, ll p) {
    if(p == 0) return 1;
    if(p == 1) return b;

    ll half = modexp(b, p/2) % mod;
    half = (half * half) % mod;
    if(p%2==1) return (half * b) % mod;
    return half % mod;
}

vector<ll> fact(1e6+1, 1);

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 2; i <= 1e6; i++) {
        fact[i] = ((fact[i-1] % mod) * i) % mod;
    }

    string s; cin >> s;
    vector<ll> freq(26, 0);
    for(auto c : s) {
        freq[c - 'a']++;
    }

    ll ans = fact[s.size()];
    for(ll i = 0; i < 26; i++) {
        // cout << ans << endl;
        ans *= modexp(fact[freq[i]], mod-2);
        ans %= mod;
    }
    cout << ans << endl;
}