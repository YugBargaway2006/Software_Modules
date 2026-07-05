#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, m; cin >> n >> k >> m;
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < n; i++) {
        ll u, v; cin >> u >> v;
        u--;

        adj[u].push_back(v);
    }

    for(auto& v : adj) {
        sort(v.rbegin(), v.rend());
    }

    sort(adj.rbegin(), adj.rend());

    ll ct = 0;
    for(ll i = 0; i < m; i++) {
        ct += adj[i][0];
        // cout << ct << endl;
    }

    vector<ll> arr;
    for(ll i = 0; i < n; i++) {
        if(i < m) {
            for(ll j = 1; j < adj[i].size(); j++) {
                arr.push_back(adj[i][j]);
            }
        } else {
            for(ll j = 0; j < adj[i].size(); j++) {
                arr.push_back(adj[i][j]);
            }
        }
    }

    sort(arr.rbegin(), arr.rend());
    // for(auto x : arr) cout << x << " "; cout << endl;

    k -= m;
    for(ll i = 0; i < k; i++) {
        ct += arr[i];
    }
    cout << ct << endl;
}