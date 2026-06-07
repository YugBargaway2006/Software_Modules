#include <bits/stdc++.h>
using namespace std;

#define ll long long

class ST {
public:
    ll n;
    vector<ll> tree;
    vector<ll> lazyA, lazyB;

    ST(ll sz) {
        n = sz;
        tree.assign(4 * n, 0);
        lazyA.assign(4 * n, 0);
        lazyB.assign(4 * n, 0);
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    ll calc(ll l, ll r, ll A, ll B) {
        ll len = r - l + 1;

        return len * A
             + B * ((l + r) * len / 2);
    }

    void apply(ll node, ll l, ll r, ll A, ll B) {
        tree[node] += calc(l, r, A, B);

        lazyA[node] += A;
        lazyB[node] += B;
    }

    void push(ll node, ll l, ll r) {
        if (lazyA[node] == 0 && lazyB[node] == 0)
            return;

        if (l != r) {
            ll mid = (l + r) / 2;

            apply(2 * node,
                  l, mid,
                  lazyA[node], lazyB[node]);

            apply(2 * node + 1,
                  mid + 1, r,
                  lazyA[node], lazyB[node]);
        }

        lazyA[node] = 0;
        lazyB[node] = 0;
    }

    void update(ll node, ll l, ll r,
                ll ql, ll qr,
                ll A, ll B) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, A, B);
            return;
        }

        push(node, l, r);

        ll mid = (l + r) / 2;

        update(2 * node,
               l, mid,
               ql, qr,
               A, B);

        update(2 * node + 1,
               mid + 1, r,
               ql, qr,
               A, B);

        tree[node] =
            merge(tree[2 * node],
                  tree[2 * node + 1]);
    }

    ll query(ll node, ll l, ll r,
             ll ql, ll qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        push(node, l, r);

        ll mid = (l + r) / 2;

        return merge(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ST st(n);
    st.build(arr, 1, 0, n - 1);

    while (q--) {

        ll t;
        cin >> t;

        if (t == 1) {
            ll a, b;
            cin >> a >> b;

            a--;
            b--;

            // add (i-a+1) = (1-a) + i
            st.update(
                1, 0, n - 1,
                a, b,
                1 - a, 1
            );
        }
        else {
            ll a, b;
            cin >> a >> b;

            a--;
            b--;

            cout
                << st.query(
                       1, 0, n - 1,
                       a, b
                   )
                << '\n';
        }
    }
}