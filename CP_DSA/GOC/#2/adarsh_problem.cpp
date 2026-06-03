// https://www.hackerrank.com/contests/goc-cdc-series-2/challenges/an-ideal-problem/problem?isFullScreen=true
// ::::::: REVISE
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll mxn = 1e5;
vector<bool> prime(1e5+1, true);

void sieve() {
    prime[0] = false;
    prime[1] = false;
    for(ll i = 2; i <= mxn; i++) {
        if(!prime[i]) continue;
        for(ll j = i+i; j <= mxn; j+=i) {
            prime[j] = false;
        }
    }
}

vector<vector<ll>> factors;
void prime_factor(ll n, ll idx) {
    for(ll i = 2; i*i <= n; i++) {
        if(prime[i] && n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            factors[idx].push_back(i);
        }
    }
    if(n > 1 && prime[n]) {
        factors[idx].push_back(n);
    }
}

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    factors.assign(n, {});
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        prime_factor(arr[i], i);
    }
    
    ll mxl = 1;
    ll l = 0;
    set<ll> came;
    for(ll r = 0; r < n; r++) {
        for(auto p : factors[r]) {
            if(came.count(p) != 0) {
                while(came.count(p) != 0) {
                    for(auto p2 : factors[l]) {
                        came.erase(p2);
                    }
                    l++;
                }
            }
            came.insert(p);
        }
        mxl = max(mxl, r-l+1);
    }
    cout << mxl << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    sieve();
    while(t--) {
        solve();
    }
    
        
    return 0;
}
