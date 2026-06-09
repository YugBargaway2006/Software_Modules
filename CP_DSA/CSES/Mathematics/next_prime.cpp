// 13 : 49  :::::::: REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool prime(ll n) {
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(ll i = 3; i <= static_cast<ll>(sqrt(n)); i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

ll solve(ll n) {
    for(ll i = 1; i <= static_cast<ll>(log(n)); i++) {
        if(prime(n+i)) return n+i;
    }
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << solve(n) << endl;
    }
}