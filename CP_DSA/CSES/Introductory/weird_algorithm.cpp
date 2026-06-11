#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long 
 
int conjecture(int n) {
    if(n%2 == 0) {
        return n/2;
    } else {
        return 3*n+1;
    }
}
 
void solve() {
    int n; cin >> n;
    
    cout << n << " ";
    while(n != 1) {
        n = conjecture(n);
        cout << n << " ";
    }
    cout << endl;
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
