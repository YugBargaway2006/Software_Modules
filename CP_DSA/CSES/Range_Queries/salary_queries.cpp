// ::::::::::::::: DEEPLY REVISE
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class FT {
public:
    ll n;
    vector<ll> bit;

    FT(ll s) {
        n = s;
        bit.assign(n + 1, 0);
    }

    void update(ll i, ll delta) {
        while(i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    ll query(ll i) {
        ll sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    ll rangeQuery(ll l, ll r) {
        if(l > r) return 0;
        return query(r) - query(l - 1);
    }
};

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<tuple<char,ll,ll>> queries;
    vector<ll> vals;

    for(ll x : arr) vals.push_back(x);

    for(ll i = 0; i < q; i++) {
        char c;
        ll a, b;
        cin >> c >> a >> b;
        queries.push_back({c, a, b});

        if(c == '!') {
            vals.push_back(b);
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    map<ll,ll> idx;
    for(ll i = 0; i < vals.size(); i++) {
        idx[vals[i]] = i + 1;   // 1-based
    }

    FT ft(vals.size());

    for(ll x : arr) {
        ft.update(idx[x], 1);
    }

    for(auto [c, a, b] : queries) {
        if(c == '?') {
            ll left = lower_bound(vals.begin(), vals.end(), a) - vals.begin() + 1;
            ll right = upper_bound(vals.begin(), vals.end(), b) - vals.begin();

            cout << ft.rangeQuery(left, right) << endl;
        }
        else {
            a--; // employee index to 0-based

            ft.update(idx[arr[a]], -1);
            ft.update(idx[b], 1);

            arr[a] = b;
        }
    }
}