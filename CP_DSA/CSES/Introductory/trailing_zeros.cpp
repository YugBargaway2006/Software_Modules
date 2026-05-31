#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long 
 
 
void solve() {
    int n; cin >> n;
    int ans = 0;
    int i = 5;
    while(i <= n) {
        ans += n/i;
        i*=5;
    }
    cout << ans << endl;
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