// 20:32  ::::::::: NEED to remember with Formulation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class FT {
public:
    ll n; vector<ll> bit;

    FT(ll s) {
        n = s;
        bit.assign(n+1, 0);
    }

    void update(ll idx, ll val) {
        while(idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll query(ll idx) {
        ll sum = 0;
        while(idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    ll rangeQuery(ll l, ll r) {
        return query(r) - query(l-1);
    }
};

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> arr(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<pair<ll, ll>>> queries(n+1);
    for(ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }

    FT ft(n);
    unordered_map<ll, ll> last;
    last.reserve(n+1);
    vector<ll> ans(q);

    for(ll i = 1; i <= n; i++) {
        if(last.count(arr[i])) {
            ft.update(last[arr[i]], -1);
        }
        ft.update(i, 1);
        last[arr[i]] = i;

        for(auto [l, idx] : queries[i]) {
            ans[idx] = ft.rangeQuery(l, i);
        }
    }

    for(auto x : ans) cout << x << endl;
}
