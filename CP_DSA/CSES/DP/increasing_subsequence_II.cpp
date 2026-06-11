// A very good question
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;
ll n;
vector<ll> arr;

class ST {
public:
    ll n; vector<ll> tree;

    ST(ll s) {
        n = s;
        tree.resize(4*n);
    }

    ll merge(ll a, ll b) {
        return (a+b) % mod;
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = arr[l] % mod;
            return;
        }

        ll mid = l+(r-l)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = val % mod;
            return;
        }

        ll mid = l+(r-l)/2;
        if(idx <= mid) {
            update(2*node, l, mid, idx, val);
        } else {
            update(2*node+1, mid+1, r, idx, val);
        }

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if(qr < l || r < ql) {
            return 0;
        }
        if(ql <= l && r <= qr) {
            return tree[node] % mod;
        }

        ll mid = l+(r-l)/2;
        return merge(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
    for (int i = 0; i < arr.size(); ++i) {
        int compressed_val = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
        arr[i] = compressed_val;
    }

    vector<ll> dp(n+1, 0);
    ST st(n+1);
    st.build(dp, 1, 0, n);
    for(ll i  =0; i < n; i++) {
        ll val = arr[i];
        ll sum = st.query(1, 0, n, 0, val-1);
        ll old = st.query(1, 0, n, val, val);
        st.update(1, 0, n, val, (sum+1+old) % mod);
    }
    cout << st.query(1, 0, n, 0, n) << endl;
}