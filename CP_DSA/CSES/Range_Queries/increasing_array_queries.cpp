// 12 : 40   :::: Understand the Formulation sum over yi - xi for i in l se r, but yi is not same for all l
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> arr;

class ST {
public:
    ll n; vector<ll> tree;

    ST(ll sz) {
        n = sz;
        tree.assign(4*sz, 1e15);
    }

    ll merge(ll a, ll b) {
        return max(a, b);
    }

    void build(vector<ll>& arr, ll node, ll l, ll r){
        if(l == r) {
            tree[node] = arr[l];
            return;
        }

        ll mid = l + (r-l) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = val;
            return;
        }

        ll mid = l + (r-l) / 2;
        if(idx <= mid) {
            update(2*node, l, mid, idx, val);
        } else {
            update(2*node+1, mid+1, r, idx, val);
        }

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if(qr < l || r < ql) return LLONG_MIN;
        if(ql <= l && r <= qr) return tree[node];

        ll mid = l + (r-l) / 2;

        return merge(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
    }
};


signed main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    arr.assign(n, 0);
    vector<ll> prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix[i] = arr[i];
        if(i > 0) prefix[i] += prefix[i-1];
    }

    ST st(n);
    st.build(arr, 1, 0, n-1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        ll mv = st.query(1,0,n-1, l, r);
        // cout << mv << endl;
        ll ans = (r-l+1)*mv + (prefix[r]);
        if(l > 0) ans -= prefix[l-1];
        cout << ans << '\n';
    }
}