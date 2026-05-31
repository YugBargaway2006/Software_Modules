#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
#define f(i,k,n) for(int i = k; i < n; i++)

void solve() {
    ll n; cin >> n;
 
    f(k, 1, n+1) {
        ll total = k*k*(k*k-1)/2;
        cout << max((long long)0, total - 4*(k-1)*(k-2)) << endl;
    }
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
