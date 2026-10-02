#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 100005;

int n;
ll M;
vector<int> adj[MAXN];

ll dp[MAXN];      // subtree contribution
ll up[MAXN];      // contribution from parent side
ll ans[MAXN];

void dfs1(int u, int p) {
    dp[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] = dp[u] * (dp[v] + 1) % M;
    }
}

void dfs2(int u, int p) {
    int sz = adj[u].size();

    vector<ll> pref(sz + 1, 1), suff(sz + 1, 1);

    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        ll cur = (v == p ? up[u] : dp[v] + 1);
        pref[i + 1] = pref[i] * cur % M;
    }

    for (int i = sz - 1; i >= 0; i--) {
        int v = adj[u][i];
        ll cur = (v == p ? up[u] : dp[v] + 1);
        suff[i] = suff[i + 1] * cur % M;
    }

    ans[u] = pref[sz];

    for (int i = 0; i < sz; i++) {
        int v = adj[u][i];
        if (v == p) continue;

        ll without = pref[i] * suff[i + 1] % M;
        up[v] = (without + 1) % M;

        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> M;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);

    up[0] = 1;
    dfs2(0, -1);

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';

    return 0;
}