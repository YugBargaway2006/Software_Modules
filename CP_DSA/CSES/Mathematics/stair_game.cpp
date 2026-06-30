// 00 : 46
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        if(i % 2 == 1) ans ^= x;
    }
    if(ans == 0) cout << "second" << endl;
    else cout << "first" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}