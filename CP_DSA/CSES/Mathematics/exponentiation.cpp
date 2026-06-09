// 13 : 58
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;

ll calculate(ll b, ll p) {
    if (p == 0) return 1;

    ll half = calculate(b, p / 2);
    half = (half * half) % mod;

    if (p % 2) {
        half = (half * (b % mod)) % mod;
    }

    return half;
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        cout << calculate(a, b) << endl;
    }
}