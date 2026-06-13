#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll mxU = LLONG_MIN;
    ll mnU = LLONG_MAX;
    ll mxV = LLONG_MIN;
    ll mnV = LLONG_MAX;

    for(ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        ll u = x + y;
        ll v = x - y;

        mxU = max(mxU, u);
        mnU = min(mnU, u);

        mxV = max(mxV, v);
        mnV = min(mnV, v);

        cout << max(mxU - mnU, mxV - mnV) << endl;
    }
}