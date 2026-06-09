// 20 : 43 ::::::: Burnside Lemma
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;

ll modexp(ll b, ll p, ll mod=mod) {
    if(p == 0) return 1LL;
    if(p == 1) return b % mod;
    ll value = modexp(b, p/2, mod);
    if(p %2 == 0) {
        return (value * value) % mod;
    } else {
        return (((value * value) % mod) * b) % mod;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;

    ll inv4 = modexp(4, mod-2);

    if(n % 2 == 0) {
        ll m = modexp(2, n*n/4);

        ll ans = (
            modexp(m, 4) +      // 2^(n^2)
            modexp(m, 2) +      // 2^(n^2/2)
            m + m               // 90 and 270
        ) % mod;

        cout << (ans * inv4) % mod << endl;
    }
    else {
        ll ans = (
            modexp(2, n*n) +
            modexp(2, (n*n+1)/2) +
            2 * modexp(2, (n*n+3)/4)
        ) % mod;

        cout << (ans * inv4) % mod << endl;
    }
}