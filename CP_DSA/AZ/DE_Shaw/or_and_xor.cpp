#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll mod = 1e9 + 7;

ll modexp(ll b, ll p, ll mod) {
    if (p == 0) return 1LL;
    if (p == 1) return b % mod;
    ll half = modexp(b, p / 2, mod);
    ll full = (half * half) % mod;
    if (p % 2)
        full = (full * (b % mod)) % mod;
    return full;
}

void solve() {
    ll n;
    cin >> n;

    unordered_map<ll, ll> freq;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        freq[x]++;
    }

    ll ans = (modexp(2, freq[0], mod) - 1 + mod) % mod;
    for (auto &it : freq) {
        if(it.first == 0) continue;
        ans = (ans + modexp(2, it.second - 1, mod)) % mod;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
}