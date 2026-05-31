#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long

void solve() {
    string s; cin >> s;
 
    int match = 1;
    int mx = 1;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == s[i-1]) {
            match++;
            mx = max(mx, match);
        } else {
            match = 1;
            mx = max(mx, match);
        }
    }
 
    cout << mx << endl;
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