// 14 : 08 :::::: Revise the process of Lift
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, q;
const ll LOG = 20;

vector<vector<ll>> up;
vector<ll> depth;

ll lift(ll node, ll k) {
    for(ll i = 0; i < LOG; i++) {
        if(k & (1LL << i)) {
            node = up[node][i];
            if(node == -1) break;
        }
    }
    return node;
}

ll lca(ll a, ll b) {
    if(depth[a] < depth[b])
        swap(a, b);

    // bring a to same depth
    a = lift(a, depth[a] - depth[b]);

    if(a == b) return a;

    for(ll i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != -1 && up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    up.assign(n, vector<ll>(LOG, -1));
    depth.assign(n, 0);

    for(ll i = 1; i < n; i++) {
        ll p;
        cin >> p;
        p--;
        up[i][0] = p;
        depth[i] = depth[p] + 1;
    }

    for(ll j = 1; j < LOG; j++) {
        for(ll i = 0; i < n; i++) {
            if(up[i][j-1] != -1)
                up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << lca(a, b) + 1 << '\n';
    }
}