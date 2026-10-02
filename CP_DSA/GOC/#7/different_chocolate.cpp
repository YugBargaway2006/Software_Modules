// https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/different-chocolates/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;

ll modexp(ll b, ll p, ll mod=mod) {
    if(p == 0) return 1;
    if(p == 1) return b % mod;
    ll half = modexp(b, p/2, mod);
    ll full = (half*half)%mod;
    if(p%2==0) {
        return full;
    }
    return (full*b)%mod;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll mxn = 1e5+1;
    vector<ll> dp(mxn, 0);
    for(ll i = 1; i < mxn; i++) {
        dp[i] = modexp(i,mod-2);
        dp[i] += dp[i-1];
        dp[i] %= mod;
    }
    
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> tp(n);
        for(ll i = 0; i < n; i++) {
            cin >> tp[i];
        }
        cout << dp[n] << endl;
    }
    return 0;
}