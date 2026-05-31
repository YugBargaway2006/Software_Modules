// 14 : 10   :::::::: Revise
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    ll n; cin >> n;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cout << (i ^ j) << ' ';
        }
        cout << '\n';
    }
}