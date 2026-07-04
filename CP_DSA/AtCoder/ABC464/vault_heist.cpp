#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll mod = 998244353;

ll modexp(ll b, ll p, ll mod) {
    if(p == 0) return 1LL;
    if(p == 1) return b % mod;
    ll half = modexp(b, p/2, mod);
    ll full = (half * half) % mod;
    if(p%2 == 1) {
        full = (full*b)%mod;
    }
    return full;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> fact(n+1, 1);
    for(ll i = 2; i <= n; i++) {
        fact[i] = (fact[i-1]*i) % mod;
    }

    ll nl = n/2;
    ll nr = n - n/2;

    // Generate Left half
    vector<vector<ll>> left_sums(nl+1);
    for(ll mask = 0; mask < (1<<nl); mask++) {
        ll cur = 0;
        ll sz = __builtin_popcount(mask);
        for(ll i = 0; i < nl; i++) {
            if((mask >> i) & 1) {
                cur += arr[i];
            } 
        }
        left_sums[sz].push_back(cur);
    }

    // Generate Prefix for left half
    vector<vector<ll>> left_prefix(nl+1);
    for(ll k = 0; k <= nl; k++) {
        sort(left_sums[k].begin(), left_sums[k].end());
        left_prefix[k].assign(left_sums[k].size()+1, 0);

        for(ll i = 0; i < left_sums[k].size(); i++) {
            ll cur = left_sums[k][i] % mod;
            left_prefix[k][i+1] = (left_prefix[k][i] + cur) % mod;
        }
    }

    vector<ll> C(n+1, 0), V(n+1, 0);

    // Process on Right Half
    for(ll mask = 0; mask < (1 << nr); mask++) {
        ll s2 = 0;
        ll c2 = __builtin_popcount(mask);

        for(ll i = 0; i < nr; i++) {
            if((mask >> i) & 1) {
                s2 += arr[nl+i];
            }
        }

        if(s2 >= x) continue;

        for(ll c1 = 0; c1 <= nl; c1++) {
            auto it = lower_bound(left_sums[c1].begin(), left_sums[c1].end(), x-s2);
            ll ct = distance(left_sums[c1].begin(), it);
            if(ct == 0) continue;

            ll total = c1 + c2;
            C[total] = (C[total] + ct) % mod;

            ll lst = left_prefix[c1][ct];
            ll rst = (ct % mod) * (s2 % mod) % mod;

            ll contri = (lst + rst) % mod;
            V[total] = (V[total] + contri) % mod;
        }
    }

    // Calculate Prob and expectiation
    ll total = 0;
    for(ll i = 0; i < n; i++) {
        total = (total + (arr[i] % mod)) % mod;
    }

    ll exp = 0;
    ll invN = modexp(fact[n], mod-2, mod);

    for(ll k = 0; k < n; k++) {
        if(C[k] == 0) continue;

        ll num = (fact[k] * fact[n-1-k]) % mod;
        ll prob = (num * invN) % mod;

        ll t1 = (C[k] * total) % mod;
        ll t2 = V[k];

        ll exsum = (t1 - t2 + mod) % mod;
        ll expcontri = (prob * exsum) % mod;

        exp = (exp + expcontri) % mod;
    }

    cout << exp << endl;
}