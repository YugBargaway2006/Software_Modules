// 11 : 35
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class ST {
public:
    ll n; vector<ll> tree, lazy;

    ST(ll sz) {
        n = sz;
        tree.assign(4*sz, 0);
        lazy.assign(4*sz, 0);
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = arr[l];
            return;
        }

        ll mid = l + (r-l)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void push(ll node, ll l, ll r){
        if(lazy[node] == 0) return;
        
        tree[node] += (r-l+1) * lazy[node];
        if(l != r) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(ll node, ll l, ll r, ll ql, ll qr, ll val) {
        push(node, l, r);

        if(qr < l || r < ql) {
            return;
        }
        if(ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        ll mid = l + (r-l) / 2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid+1, r, ql, qr, val);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    ll query(ll node, ll l, ll r, ll idx) {
        push(node, l, r);
        if(l == r) {
            return tree[node];
        }

        ll mid = l + (r-l) / 2;
        if(idx <= mid) {
            return query(2*node, l, mid, idx);
        } else {
            return query(2*node+1, mid+1, r, idx);
        }
    }
};


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ST st(n);
    st.build(arr, 1, 0, n-1);

    while(q--) {
        ll x; cin >> x;
        if(x == 1) {
            ll a, b, u; cin >> a >> b >> u;
            a--; b--;
            st.update(1, 0, n-1, a, b, u);
        } else {
            ll k; cin >> k; k--;
            cout << st.query(1, 0, n-1, k) << endl;
        }
    }
}