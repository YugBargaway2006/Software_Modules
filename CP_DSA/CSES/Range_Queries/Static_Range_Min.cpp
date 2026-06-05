// 20 : 41
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class ST {
public:
    ll n;
    vector<ll> tree;

    ST(ll i) {
        n = i;
        tree.assign(4*i, 0);
    }

    ll merge(ll a, ll b) {
        return min(a,b);
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = arr[l];
            return;
        }

        ll mid = l+(r-l)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = val;
            return;
        }

        ll mid = l+(r-l)/2;
        if(idx <= mid) {
            update(2*node, l, mid, idx, val);
        } else {
            update(2*node+1, mid+1,r, idx,val);
        }

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if(qr < l || r < ql) {
            return LLONG_MAX;
        }
        if(ql <= l && r <= qr) {
            return tree[node];
        }

        ll mid = l+(r-l)/2;

        return merge(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
    }
};


ll n, q;
vector<ll> arr;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    arr.assign(n, 0);
    ST st(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    st.build(arr, 1, 0, n-1);

    while(q--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        cout << st.query(1, 0, n-1, a, b) << endl;
    }
}
