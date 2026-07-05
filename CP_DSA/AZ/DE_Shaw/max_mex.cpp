#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

set<ll> came;

ll small(ll y, ll x, ll mex) {
    for(ll i = mex; i < 1e5+1; i++) {
        if((y-i)%x==0 && came.count(i) == 0) {
            return i;
        }
    }
    return -1;
}

void solve() {
    came.clear();
    ll n, x; cin >> n >> x;
    ll mex = 0;
    for(ll i = 0; i < n; i++) {
        ll y; cin >> y;
        if((y - mex) % x == 0) {
            came.insert(mex);
            while(came.count(mex) != 0) {
                mex++;
            }
        }
        else {
            ll val = small(y, x, mex);
            came.insert(val);
        }
        cout << mex << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    // cout << endl;
    while(t--) {
        solve();
    }
}

