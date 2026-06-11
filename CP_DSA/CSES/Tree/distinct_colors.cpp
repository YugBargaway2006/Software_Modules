// 11 : 52  :::: Segment Trees
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll mn = 2e5+1;

struct BIT {
    vector<ll> bit;
    ll n;

    BIT(ll n) : n(n+1), bit(n+1) {}

    ll sum(ll r) {
        r++;
        ll ret = 0;
        while(r > 0) {
            ret += bit[r];
            r -= r & -r;
        }
        return ret;
    }

    void update(ll idx, ll v) {
        idx++;
        while(idx < n) {
            bit[idx] += v;
            idx += idx & -idx;
        }
    }
};

vector<ll> tour(mn), color(mn), answer(mn), lend(mn);
vector<vector<ll>> adj(mn);
ll idx = 0;

void dfs(ll u, ll p) {
    lend[u] = idx;
    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    tour[idx] = u;
    idx++;
} 

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, u, v;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for(ll i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    BIT bit(n);

    map<ll, ll> last;
    for(ll i = 0; i < n; i++) {
        if(last.count(color[tour[i]])) {
            bit.update(last[color[tour[i]]], -1);
        }
        last[color[tour[i]]] = i;
        bit.update(i, 1);
        answer[tour[i]] = bit.sum(i) - bit.sum(lend[tour[i]] - 1);
    }

    for(ll i = 1; i <= n; i++) cout << answer[i] << " ";
    cout << endl;
}