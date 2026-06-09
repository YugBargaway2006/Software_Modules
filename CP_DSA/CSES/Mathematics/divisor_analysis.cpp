// 23 : 43
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll mod = 1e9 + 7;

ll modexp(ll b, ll p) {
    if(p == 0) return 1;
    if(p == 1) return b;

    ll half = modexp(b, p/2) % mod;
    half = (half * half) % mod;
    if(p%2==1) return (half * b) % mod;
    return half % mod;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll num = 1, sum = 1, prod = 1;
    ll num_exp = 1;
    for(ll i = 0; i < n; i++) {
        ll x, p; cin >> x >> p;
        num = (num * (p+1)) % mod;
        sum = ((sum * (modexp(x, p+1) - 1)) % mod * modexp(x-1, mod-2)) % mod;
        
        prod = modexp(prod, p + 1);
        ll extra = (num_exp * ((p * (p + 1) / 2) % (mod-1))) % (mod-1);
        prod = (prod * modexp(x, extra)) % mod;

        num_exp = (num_exp * (p + 1)) % (mod-1);
    }
    cout << num << " " << sum << " " << prod << endl;
}