// 17 : 05   ::::: Revise segment tree with visualization
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll t = 0;
ll n, q;
vector<ll> item;
vector<vector<ll>> adj;
vector<ll> tin;
vector<ll> tout;
vector<ll> flat;
vector<ll> seg;

void dfs(ll u, ll p) {
    tin[u] = t++;
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    tout[u] = t-1;
}

void build(ll i, ll l, ll r) {
    if(l == r) {
        seg[i] = flat[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(2*i, l, mid);
    build(2*i+1, mid+1, r);

    seg[i] = seg[2*i] + seg[2*i + 1];
}

void update(ll i, ll l, ll r, ll pos, ll val) {
    if(l == r) {
        seg[i] = val;
        return;
    } 
    ll mid = l + (r - l) / 2;
    if(pos <= mid) {
        update(2*i, l, mid, pos, val);
    } else {
        update(2*i+1, mid+1, r, pos, val);
    }

    seg[i] = seg[2*i] + seg[2*i + 1];
}

ll query(ll i, ll l, ll r, ll ql, ll qr) {
    if(qr < l || r < ql) {
        return 0;
    } 
    if(ql <= l && r <= qr) {
        return seg[i];
    }

    ll mid = l + (r - l) / 2;
    return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, qr);

}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    item.resize(n);
    adj.resize(n);
    tin.assign(n, 0);
    tout.assign(n, 0);
    seg.assign(4*n, 0);
    for(ll i = 0; i < n; i++) cin >> item[i];
    for(ll i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    flat.assign(n, 0);
    for(ll i = 0; i< n; i++) {
        flat[tin[i]] = item[i];
    }

    build(1, 0, n-1);

    while(q--) {
        ll x; cin >> x;
        if(x == 1) {
            ll s, v; cin >> s >> v; s--;
            update(1, 0, n-1, tin[s], v);
            
        } else {
            ll s; cin >> s; s--;
            cout << query(1, 0, n-1, tin[s], tout[s]) << endl;
        }
    }
}