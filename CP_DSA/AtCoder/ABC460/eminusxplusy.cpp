// 14 : 31   :::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll __int128
#define endl '\n'

long long mod = 998244353;

void solve() {
    long long n, m; cin >> n >> m;
    long long ans = 0;
    ll l = 1; 
    while (l <= n) {    // This helped solve the problem
        ll p = l * 10;
        ll r = min((ll)n, p - 1);

        ll g = __gcd((ll)m, p - 1);
        ll nx = n / (m / g);
        ll ny = r - l + 1;

        ans = (ans + (nx % mod) * (ny % mod)) % mod;

        if (l > n / 10) break;   // prevent overflow
        l *= 10;
    }

    cout << (ans%mod+mod)%mod << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long t; cin >> t;
    while(t--) {
        solve();
    }
}