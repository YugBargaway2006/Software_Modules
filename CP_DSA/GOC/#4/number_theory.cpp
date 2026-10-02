// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/just-a-simple-sum-3/problem?isFullScreen=true
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> factors;
    for(ll p =2; p*p <= n; p++) {
        ll ct = 0;
        while(n % p == 0) {
            n /= p;
            ct++;
        }
        if(ct != 0) factors.push_back(2*ct);
    }
    if(n > 1) factors.push_back(2);
    
    ll ans = 1;
    for(auto x : factors) ans *= (x+1);
    cout << ans << endl;
    
    return 0;
}
