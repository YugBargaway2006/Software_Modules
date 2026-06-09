// :::::::::: REVISE WITH VIDEO
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll modexp(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }
    return res;
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;

    for (ll k = 0; k < n; k++) {
        ans = (ans + modexp(m, gcd(n, k))) % MOD;
    }

    ans = (ans * modexp(n, MOD - 2)) % MOD;

    cout << ans << '\n';
}