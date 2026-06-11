// 13 : 49  :::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;

ll modexp(ll b, ll p) {
    if(p == 0) return 1;
    if(p == 1) return b % mod;

    ll half = modexp(b, p/2) % mod;
    half = (half * half) % mod;
    if(p%2==1) return (half * b) % mod;
    return half % mod;
}

vector<ll> fact(1e6+1, 1);
vector<ll> invfact(1e6+1, 1);

ll combi(ll n, ll m) {
    ll ans = 1;
    ans *= fact[n];
    ans %= mod;
    ans *= modexp(fact[m], mod-2);
    ans %= mod;
    ans *= modexp(fact[n-m], mod-2);
    ans %= mod;
    return ans;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 2; i <= 1e6; i++) {
        fact[i] = ((fact[i-1] % mod) * i) % mod;
    }
    invfact[1e6] = modexp(fact[1e6], mod-2);
    for(ll i = 1e6-1; i >= 0; i--) {
        invfact[i] = ((invfact[i+1] % mod) * (i+1)) % mod;
    }

    ll n; cin >> n;

    ll ans = 0;
    for(ll i = 0; i <= n; i++) {
        ll req = invfact[i];
        ans += (i % 2 == 0) ? req : -req;
        ans %= mod;
    }
    if(ans < 0) ans = ((ans % mod) + mod) % mod; 
    cout << (ans * fact[n]) % mod << endl;
}