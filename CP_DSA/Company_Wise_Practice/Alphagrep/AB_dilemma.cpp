// https://maang.in/contests/attempts/86601?problem_id=520

// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mxn = 1e6+1;
vector<bool> pn(mxn, true);
vector<ll> primes;

void sieve() {
    for(ll i = 2; i*i < mxn; i++) {
        if(!pn[i]) continue; 
        for(ll j = i+i; j < mxn; j+=i) {
            pn[j] = false;
        }
    }

    for(ll i = 2; i < mxn; i++) {
        if(pn[i]) primes.push_back(i);
    }
}


void solve() {
    ll a, b; cin >> a >> b;
    ll ct = 1;
    for(auto p : primes) {
        if(a % p == 0 && b % p == 0) {
            ct +=1;
            while(a%p==0) a/=p;
            while(b%p==0) b/=p;
        }
        while(a%p==0) a/=p;
        while(b%p==0) b/=p;
    }

    if((b != 1 && a % b == 0) || (a != 1 && b % a == 0)) {
        ct++;
    }

    cout << ct << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}