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

ll solve(ll n, ll m) {
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

    ll n; cin >> n;
    string s; cin >> s;
    ll x = 0, y = 0;
    for(auto c : s) {
        if(c =='(') x++;
        if(c ==')') y++;
        if(x < y || x > n/2) {
            cout << 0 << endl;
            return 0;
        }
    }
    if(n % 2 == 1) cout << 0 << endl;
    else if(s.size() == n) {
        cout << (x == y ? 1 : 0) << endl;
    }
    else {
        n = n/2;
        ll a = solve(2*n-x-y, n-x);
        ll b = (n-x-1 >= 0 ? solve(2*n-x-y, n-x-1) : 0);
        ll ans = a-b;
        ans %= mod;
        ans += mod;
        ans %= mod;
        cout << ans << endl;
    }
}