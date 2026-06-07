#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class ST {
public:
    ll n;
    vector<ll> tree;

    vector<ll> lazyAdd;
    vector<ll> lazySet;
    vector<bool> hasSet;

    ST(ll s) {
        n = s;
        tree.resize(4 * n);

        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        hasSet.assign(4 * n, false);
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }

        ll mid = l + (r - l) / 2;

        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void applySet(ll node, ll l, ll r, ll val) {
        tree[node] = (r - l + 1) * val;

        hasSet[node] = true;
        lazySet[node] = val;
        lazyAdd[node] = 0;
    }

    void applyAdd(ll node, ll l, ll r, ll val) {
        tree[node] += (r - l + 1) * val;

        if (hasSet[node])
            lazySet[node] += val;
        else
            lazyAdd[node] += val;
    }

    void push(ll node, ll l, ll r) {
        if (l == r) return;

        ll mid = l + (r - l) / 2;

        if (hasSet[node]) {
            applySet(2 * node, l, mid, lazySet[node]);
            applySet(2 * node + 1, mid + 1, r, lazySet[node]);

            hasSet[node] = false;
        }

        if (lazyAdd[node] != 0) {
            applyAdd(2 * node, l, mid, lazyAdd[node]);
            applyAdd(2 * node + 1, mid + 1, r, lazyAdd[node]);

            lazyAdd[node] = 0;
        }
    }

    void updateBulk(ll node, ll l, ll r,
                    ll ql, ll qr,
                    ll val, bool inc) {

        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            if (inc)
                applyAdd(node, l, r, val);
            else
                applySet(node, l, r, val);

            return;
        }

        push(node, l, r);

        ll mid = l + (r - l) / 2;

        updateBulk(2 * node, l, mid, ql, qr, val, inc);
        updateBulk(2 * node + 1, mid + 1, r, ql, qr, val, inc);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(ll node, ll l, ll r,
             ll ql, ll qr) {

        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        push(node, l, r);

        ll mid = l + (r - l) / 2;

        return merge(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            ll a, b, x;
            cin >> a >> b >> x;

            a--;
            b--;

            st.updateBulk(1, 0, n - 1, a, b, x, true);
        }
        else if (t == 2) {
            ll a, b, x;
            cin >> a >> b >> x;

            a--;
            b--;

            st.updateBulk(1, 0, n - 1, a, b, x, false);
        }
        else {
            ll a, b;
            cin >> a >> b;

            a--;
            b--;

            cout << st.query(1, 0, n - 1, a, b) << endl;
        }
    }
}