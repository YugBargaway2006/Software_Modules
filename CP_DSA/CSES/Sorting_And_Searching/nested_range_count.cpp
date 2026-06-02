// 20 : 54 :::::::::  Check logic
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class Range {
public: 
    ll l, r, idx;
};

class FT {
public:
    ll n; vector<ll> bit;

    FT(ll s) {
        n = s;
        bit.assign(n+1, 0);
    }

    void add(ll idx, ll val) {
        while(idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        } 
    }

    ll sum(ll idx) {
        ll res = 0;
        while(idx > 0) {
            res+= bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    ll query(ll l, ll r) {
        return sum(r) - sum(l-1);
    }
};


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<Range> arr(n);
    vector<ll> vals;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].l >> arr[i].r;
        arr[i].idx = i;
        vals.push_back(arr[i].r);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto get = [&](ll x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    sort(arr.begin(), arr.end(), [](Range& a, Range& b) {
        if(a.l == b.l) return a.r > b.r;
        return a.l < b.l; 
    });

    vector<ll> contains(n), contained(n);
    ll m = vals.size();
    
    // Contains
    FT bit1(m);
    for(ll i = n-1; i >= 0; i--) {
        ll r = get(arr[i].r);
        contains[arr[i].idx] = bit1.sum(r);
        bit1.add(r, 1);
    }

    // contained 
    FT bit2(m);
    for(ll i = 0; i < n; i++) {
        ll r = get(arr[i].r);
        contained[arr[i].idx] = i - bit2.sum(r-1);
        bit2.add(r, 1);
    }

    for(auto x : contains) cout << x << " "; cout << endl;
    for(auto x : contained) cout << x << " "; cout << endl;
}