// 13 : 58  :::::::: Remember Euler Totient
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// ll mod = 1e9+7;

ll calculate(ll b, ll p, ll mod) {
    if (p == 0) return 1;

    ll half = calculate(b, p / 2, mod);
    half = (half * half) % mod;

    if (p % 2) {
        half = (half * (b % mod)) % mod;
    }

    return half % mod;
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << calculate(a, calculate(b, c, 1e9+6), 1e9+7) << endl;
    }
}