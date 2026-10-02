// 14 : 37   :::::: Remember the formulation on Tree
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<ll> prr;
vector<ll> d;
vector<vector<ll>> adj;

void solve() {
    ll n; cin >> n;
    prr.assign(n, 0);
    d.assign(n, 0);
    adj.assign(n, {});
    for(ll i = 0; i < n; i++) {
        cin >> prr[i];
    }
    for(ll i = 0 ; i < n; i++) {
        cin >> d[i];
    }

    map<ll, vector<ll>> ct;
    ct[1].push_back(n-1);
    if(d[n-1] != 0) {
        cout << -1 << endl;
        return;
    }
    for(ll i = n-2; i >= 0; i--) {
        // Count Possibility
        ll count = 0;
        for(ll j = i+1; j < n; j++) {
            if(prr[i] < prr[j]) count++;
        }
        if(count < d[i]) {
            cout << -1 << endl;
            return;
        }

        // TODO : It can point multiple next numbers
        for(auto val : ct[d[i]]) {
            if(prr[val] > prr[i]) {
                adj[i].push_back(val);
            }
        }
        ct[d[i]+1].push_back(i);
    }

    // Topo sort
    priority_queue<ll> q;
    vector<ll> indegree(n, 0);
    vector<bool> vis(n, false);
    for(ll i = 0; i < n; i++) {
        for(auto v : adj[i]) {
            indegree[v]++;
        }
    }
    for(ll i = 0 ; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            vis[i] = true;
        }
    }
    vector<ll> trav(n);
    ll node = 0;
    while(!q.empty()) {
        auto u = q.top(); q.pop();
        trav[node] = u;
        node++;
        for(auto v : adj[u]) {
            if(vis[v]) continue;
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    for(auto t : trav) cout << t+1 << " ";
    cout << endl;
}


signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}