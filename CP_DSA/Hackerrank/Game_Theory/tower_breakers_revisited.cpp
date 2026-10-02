#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

ll mxn = 1e6+1;
vector<ll> primes;
vector<ll> pn(mxn, true);

void sieve() {
    for(ll i = 2; i*i < mxn; i++) {
        for(ll j = i+i; j < mxn; j += i) {
            pn[j] = false;
        }
    }
    
    for(ll i = 2; i < mxn; i++) {
        if(pn[i]) primes.push_back(i);
    }
}

void solve() {
    ll n; cin >> n;
    ll div = 0;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        ll cur = 1;
        ll ct = 0;
        for(auto p : primes) {
            // if(x % p == 0) ct++;
            while(x % p == 0) {
                x /= p;
                ct += 1;
            }
            cur *= (ct + 1);
        }
        if(x != 1) {
            // cur *= 2;
            ct += 1;
        }
        // cur -= 1;
        
        div = div ^ ct;
        // cout << ct << endl;
    }
    if(div == 0) cout << "2" << endl;
    else cout << "1" << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
