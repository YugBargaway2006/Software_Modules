#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long

 
void solve() {
    int a, b; cin >> a >> b;
 
    int n, m; 
    // debug(1);
    if((2*b-a) % 3 != 0 || (2*a-b) % 3 != 0) {
        // debug(2);
        cout << "NO" << endl;
        return;
    }
    m = (2*b-a)/3;
    n = (2*a-b)/3;
 
    if(m < 0 || n < 0) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
 
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    // int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}
