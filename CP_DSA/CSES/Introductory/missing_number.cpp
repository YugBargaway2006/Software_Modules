#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long

 
void solve() {
    int n; cin >> n;
    
    vector<ll> a(n-1);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int sum = 0;
    for(auto i : a) {
        sum += i;
    }
 
    int total = n*(n+1)/2;
    cout << total - sum << endl;
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
 
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
