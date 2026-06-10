// 14 : 50
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9+7;
ll base = 3;
vector<ll> pw;

ll modexp(ll b, ll p) {
    ll res = 1;
    while(p) {
        if(p & 1) res = res * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return res;
}

class ST {
public:
    ll n; vector<vector<ll>> tree;

    ST(ll s) {
        n = s;
        tree.resize(4*n);
    }

    vector<ll> merge(vector<ll> a, vector<ll> b) {
        return {((a[0] * pw[b[1]]) % mod + b[0]) % mod, a[1]+b[1]};   // Fix 1 : a[1] -> b[1]
    }

    void build(vector<ll>& arr, ll node, ll l, ll r) {
        if(l == r) {
            tree[node] = {arr[l], 1};
            return;
        }

        ll mid = l + (r-l) / 2;

        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);

        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(ll node, ll l, ll r, ll idx, ll val) {
        if(l == r) {
            tree[node] = {val, 1};
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
            return {0, 0};
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
    string s; cin >> s;

    pw.resize(n + 1);
    pw[0] = 1;
    for(int i = 1; i <= n; i++) {
        pw[i] = pw[i-1] * base % mod;
    }
    
    vector<ll> hsh(s.size());
    for(ll i = 0; i < s.size(); i++) {
        hsh[i] = s[i];
    }

    vector<ll> rev = hsh;
    reverse(rev.begin(), rev.end());

    ll m = s.size();
    ST fwd(m); 
    ST bwd(m);

    fwd.build(hsh, 1, 0, m-1);
    bwd.build(rev, 1, 0, m-1);

    while(q--) {
        ll t; cin >> t;
        if(t == 1) {
            ll k; char x; cin >> k >> x; k--;
            fwd.update(1, 0, m-1, k, x); 
            bwd.update(1, 0, m-1, m-k-1, x); 
        } else {
            ll a, b; cin >> a >> b; a--; b--;
            if(fwd.query(1, 0, m-1, a, b) == bwd.query(1, 0, m-1, m-1-b, m-1-a)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            } 
        }
    }
}