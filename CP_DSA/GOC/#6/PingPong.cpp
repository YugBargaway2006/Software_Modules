// https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/pingpong/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;
ll n;
ll mxn = 2e5+1;
vector<ll> fact(mxn);
vector<ll> invfact(mxn);

ll modexp(ll b, ll p, ll mod=mod) {
    if(p == 0) return 1;
    if(p == 1) return b % mod;
    
    ll half = modexp(b, p/2, mod);
    ll res = (half * half) % mod;
    if(p % 2 == 0) {
        return res;
    } 
    return (res * b) % mod;
}

void solve() {
    ll n; cin >> n;
    ll x, y; cin >> x >> y;
    
    if(x < n && y < n) {
        cout << 0 << endl; return;
    }
    if(abs(x - y) < 2) {
        cout << 0 << endl; return;
    } 
    if((x > n || y > n) && abs(x-y) != 2) {
        cout << 0 << endl; return;
    }
    
    if((x == n && y < n) || (x < n && y == n)) {
        ll ans = 1;
        ans = (ans * fact[x+y-1]) % mod;
        ans = (ans * invfact[min(x, y)]) % mod;
        ans = (ans * invfact[max(x, y) - 1]) % mod;
        cout << ans << endl;
        return;
    }
    
    ll ans = 1;
    ans = (ans * fact[2*n - 2]) % mod;
    ans = (ans * invfact[n-1]) % mod;
    ans = (ans * invfact[n-1]) % mod;
    x -= n-1;
    y -= n-1;
    ans = (ans * modexp(2, min(x, y))) % mod;
    cout << ans << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fact[0] = 1;
    for(ll i = 1; i < mxn; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    ll nfinv = modexp(fact[mxn-1], mod-2);
    invfact[mxn-1] = nfinv;
    for(ll i = mxn-2; i >= 0; i--) {
        invfact[i] = modexp(fact[i], mod-2);
    }
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
