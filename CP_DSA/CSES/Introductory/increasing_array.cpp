#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int cost = 0;
    for(ll i = 1; i < n; i++) {
        cost += max((long long)0, a[i-1]-a[i]);
        a[i] = max(a[i], a[i-1]);
    }
    cout << cost << endl;
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
 
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}