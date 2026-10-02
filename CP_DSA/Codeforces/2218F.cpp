// 14 : 37   :::::: Remember the formulation on Tree
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'



void solve() {
    ll x, y; cin >> x >> y;
    ll n = x+y;
    ll d = y-x;
    if((x == 0 && n%2 == 0) || (n/2 < x)) {
        cout << "NO" << endl;
        return;
    }   
    cout << "YES" << endl;

    ll mm = 2*x + (d%2);
    for(ll i = 2; i < mm+1; i++) {
        cout << i-1 << " " << i << endl;
    }
    for(ll i = mm+1; i < n+1; i++) {
        cout << mm << " " << i << endl;
    }
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}