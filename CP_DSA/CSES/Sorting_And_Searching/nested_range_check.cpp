// 20 : 54 :::::::::  Check logic
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class Range {
public:
    ll l, r, idx;
};

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<Range> arr(n);
    for(ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        arr[i].l = x;
        arr[i].r = y;
        arr[i].idx = i;
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
        if(a.l == b.l) return a.r > b.r;
        else return a.l < b.l;
    });

    vector<ll> contains(n), contained(n);
    ll mR = 0;
    for(auto x : arr) {
        if(x.r <= mR) contained[x.idx] = 1;
        mR = max(mR, x.r);
    }

    ll mr = LLONG_MAX;
    for(ll i = n-1; i>=0 ; i--) {
        if(arr[i].r >= mr) contains[arr[i].idx] = 1;
        mr = min(mr, arr[i].r);
    }

    for(auto i : contains) cout << i << " ";
    cout << endl;
    for(auto i : contained) cout << i << " ";
    cout << endl;
}