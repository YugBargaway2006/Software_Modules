// https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/deku-prime-love/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<bool> prime;
vector<ll> pr;

void sieve(ll n) {
    prime.assign(n + 1, true);

    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;

    for(ll i = 2; i * i <= n; i++) {
        if(!prime[i]) continue;

        for(ll j = i * i; j <= n; j += i)
            prime[j] = false;
    }

    for(ll i = 2; i <= n; i++) {
        if(prime[i]) pr.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> arr(n);

    ll mx = 0;
    ll mn = LLONG_MAX;

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }

    ll limit = sqrt(mx) + 1;

    sieve(limit);

    vector<bool> seg(mx - mn + 1, true);

    for(ll p : pr) {
        ll start = max(p * p,
                       ((mn + p - 1) / p) * p);

        for(ll x = start; x <= mx; x += p)
            seg[x - mn] = false;
    }

    if(mn == 0) seg[0] = false;
    if(mn <= 1 && 1 <= mx) seg[1 - mn] = false;

    ll cur = 0;
    ll ans = 0;

    for(ll x : arr) {
        bool isPrime;

        if(x <= limit)
            isPrime = prime[x];
        else
            isPrime = seg[x - mn];

        if(isPrime) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 0;
        }
    }

    cout << ans << endl;
}