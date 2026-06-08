// 17 : 47   :::::: Revise Fenwick Tree with Visualization
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    
    void update(int pos, ll dif) {
        for(; pos < s.size(); pos |= pos + 1) {
            s[pos] += dif;
        }
    } 

    ll query(ll pos) {
        ll res = 0;
        for(; pos > 0; pos &= pos-1) {
            res += s[pos-1];
        }
        return res;
    }
};

ll n, q;
ll timer = 0;
vector<ll> arr;
vector<vector<ll>> adj;
vector<ll> st, en;

void dfs(ll u, ll p) {
    st[u] = timer++;
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    en[u] = timer-1;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    FT ft(n+1);
    adj.assign(n+1, {});
    arr.assign(n+1, 0);
    st.assign(n+1, 0);
    en.assign(n+1, 0);
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(ll i = 0; i < n-1; i++) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(ll i = 1; i <= n; i++) {
        ft.update(st[i], arr[i]);
        ft.update(en[i]+1, -arr[i]);
    }

    for(ll i = 0; i < q; i++) {
        ll type, s;
        cin >> type >> s;
        if(type == 1) {
            ll x; cin >> x;
            ft.update(st[s], x-arr[s]);
            ft.update(en[s]+1, -(x-arr[s]));
            arr[s] = x;
        }
        if(type == 2) cout << ft.query(st[s] + 1) << endl;
    }
}
