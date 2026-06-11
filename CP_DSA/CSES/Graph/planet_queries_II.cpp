// 21 : 44
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll n, q;
ll mx = 30;
vector<ll> t;
vector<vector<ll>> bj;
vector<ll> dist;
vector<bool> vis;

ll jump(ll a, ll d) {
    if(d < 0) return -1;   // Helped solve the problem
    for(int i = 0; i < mx; i++) {
        if(d & (1 << i)) a = bj[a][i];
    }
    return a;
}

ll dfs(ll u) {
    if(vis[u]) return dist[u];
    vis[u] = true;
    dist[u] = dfs(t[u]) + 1;
    return dist[u];
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    t.assign(n, 0);
    dist.assign(n, 0);
    vis.assign(n, false);
    bj.assign(n, vector<ll>(mx, 0));
    for(ll i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
        bj[i][0] = t[i];
    }

    for(ll i = 1; i < 30; i++) {
        for(ll j = 0; j < n; j++) {
            bj[j][i] = bj[bj[j][i-1]][i-1];
        }
    }

    for(ll i = 0; i < n; i++) {
        if(!vis[i]) dfs(i);
    }

    // for(auto i : dist) cout << i << " "; cout << endl;

    while(q--) {
        ll a, b; cin >> a >> b; a--; b--;

        ll ce = jump(a, dist[a]);
        // cout << ce << endl;

        if(jump(a, dist[a] - dist[b]) == b) {
            cout << dist[a] - dist[b] << endl;
        } else if(jump(ce, dist[ce] - dist[b]) == b) {
            cout << dist[ce] - dist[b] + dist[a] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
}