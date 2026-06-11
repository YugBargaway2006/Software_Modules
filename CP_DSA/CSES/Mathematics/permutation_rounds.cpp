// 16 : 05
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e9 + 7;

ll modexp(ll b, ll p) {
    if(p == 0) return 1;
    if(p == 1) return b;

    ll half = modexp(b, p/2) % mod;
    half = (half * half) % mod;
    if(p%2==1) return (half * b) % mod;
    return half % mod;
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> child(n);
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        child[i] = x-1;
    }

    vector<ll> bfsall;
    vector<bool> vis(n, false);
    for(ll i = 0; i < n; i++) {
        if(vis[i]) continue;

        queue<ll> q;
        ll ct = 0;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            ll u = q.front(); q.pop();
            ct++;
            // cout << u << " ";
            ll v = child[u];
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
        }
        // cout << endl;

        bfsall.push_back(ct);
    }

    map<ll,ll> mxpow;
    
    for(ll len : bfsall) {
        ll x = len;
        for(ll f = 2; f*f <= x; f++) {
            ll pw = 0;
            while(x % f == 0) {
                x /= f;
                pw++;
            }
            if(pw) mxpow[f] = max(mxpow[f], pw);
        }
        if(x > 1) mxpow[x] = max(mxpow[x], 1LL);
    }

    ll ans = 1;
    for(auto [prime, pw] : mxpow) {
        ans = (ans * modexp(prime, pw)) % mod;
    }

    cout << ans << endl;


}