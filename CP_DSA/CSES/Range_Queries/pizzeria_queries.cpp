// :::::::::: Remember how two segemnt trees are used
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class ST {
public:
    ll n;
    vector<ll> tree;

    ST(ll sz) {
        n = sz;
        tree.assign(4 * n, LLONG_MAX);
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        ll mid = (l + r) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        ll mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || r < ql) return LLONG_MAX;
        if (ql <= l && r <= qr) return tree[node];

        ll mid = (l + r) / 2;

        return min(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n), leftv(n), rightv(n);

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        leftv[i] = arr[i] - i;
        rightv[i] = arr[i] + i;
    }

    ST st1(n), st2(n);

    st1.build(leftv, 1, 0, n - 1);
    st2.build(rightv, 1, 0, n - 1);

    while (q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll k, x;
            cin >> k >> x;
            k--;

            st1.update(1, 0, n - 1, k, x - k);
            st2.update(1, 0, n - 1, k, x + k);
        }
        else {
            ll k;
            cin >> k;
            k--;

            ll ans = min(
                st1.query(1, 0, n - 1, 0, k) + k,
                st2.query(1, 0, n - 1, k, n - 1) - k
            );

            cout << ans << '\n';
        }
    }
}