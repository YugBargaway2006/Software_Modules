// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/sum-and-xor/problem?isFullScreen=true
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll s, x; cin >> s >> x;
    ll c = (s - x) / 2;

    if (s < x || ((s - x) & 1) || (c & x)) {
        cout << "-1 -1\n";
        return;
    }

    ll a = c;
    ll b = c;

    for(int i = 0; i < 62; i++) {
        if(x & (1LL << i))
            b |= (1LL << i);
    }

    cout << a << " " << b << '\n';
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
