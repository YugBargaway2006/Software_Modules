// 11 : 02   :::::::: Remember how Maximum Subarray Sum propagates.
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


class ST {
public:
    ll n;
    vector<vector<ll>> tree;

    ST(ll sz) {
        n = sz;
        tree.assign(4*sz, {});
    }

    vector<ll> merge(vector<ll>& a, vector<ll>& b) {
        vector<ll> response(4); // MSubarrayS, TotalS, MPrefixS, MSuffixS
        response[0] = max({a[0], b[0], a[3]+b[2]});
        response[1] = a[1]+b[1];
        response[2] = max(a[2], a[1]+b[2]);
        response[3] = max(b[3], a[3]+b[1]);
        return response;
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = {max(0LL, arr[l]), arr[l], max(0LL, arr[l]), max(0LL, arr[l])};
            return;
        }

        ll mid = l + (r-l) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = {max(0LL, val), val, max(0LL, val), max(0LL, val)};
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

    vector<ll> query(ll node, ll l, ll r, ll ql, ll qr) {
        if(qr < l || r < ql) {
            return {0, 0, 0, 0};
        }
        if(ql <= l && r <= qr) {
            return tree[node];
        }

        ll mid = l + (r-l)/2;

        vector<ll> r1 = query(2*node, l, mid, ql, qr);
        vector<ll> r2 = query(2*node+1, mid+1, r, ql, qr);
        return merge(r1, r2);
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

    ST st(n);
    st.build(arr, 1, 0, n-1);

    while(q--) {
        ll a, b; cin >> a >> b; a--; b--;
        cout << max(0LL, st.query(1, 0, n-1, a, b)[0]) << endl;
    }
}