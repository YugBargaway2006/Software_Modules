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
        return max(a, b);
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
        
        tree[node] += lazy[node];
        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];     // Corrected Thing. Note it
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

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        push(node, l, r);
        if(qr < l || r < ql) {
            return LLONG_MIN;
        }
        if(ql <= l && r <= qr) {
            return tree[node];
        }

        ll mid = l + (r-l) / 2;
        return merge(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
    }
};


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> arr(n);
    vector<ll> prefix(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i] = arr[i];
        if(i > 0) prefix[i] += prefix[i-1];
    }

    // for(auto x : prefix) cout << x << " "; cout << endl;

    ST st(n);
    st.build(prefix, 1, 0, n-1);

    while(q--) {
        ll x; cin >> x;
        if(x == 1) {
            ll k, u; cin >> k >> u;
            k--;
            st.update(1, 0, n-1, k, n-1, - arr[k] + u);
            arr[k] = u;
        } else {
            ll a, b; cin >> a >> b; a--; b--;
            ll ans = st.query(1, 0, n-1, a, b);
            if (a > 0) {
                ans -= st.query(1, 0, n - 1, a - 1, a - 1);
            }
            cout << max(0LL, ans) << endl;
        }
    }
}