#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class ST {
public:
    ll n;
    vector<ll> tree;

    ST(ll sz) {
        n = sz;
        tree.assign(4 * n + 5, 0);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = max(tree[node], val);
            return;
        }

        ll mid = (l + r) / 2;

        if(idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if(qr < l || r < ql) return 0;

        if(ql <= l && r <= qr) return tree[node];

        ll mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> h(n), a(n);

    for(ll i = 0; i < n; i++) cin >> h[i];
    for(ll i = 0; i < n; i++) cin >> a[i];

    ST st(n);

    ll ans = 0;

    for(ll i = 0; i < n; i++) {
        ll best = 0;

        if(h[i] > 1)
            best = st.query(1, 1, n, 1, h[i] - 1);

        ll cur = best + a[i];

        st.update(1, 1, n, h[i], cur);

        ans = max(ans, cur);
    }

    cout << ans << endl;
}